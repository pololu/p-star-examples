# Generates MPLAB X project files for all the examples:
#
# Makefile
# nbproject/configurations.xml
# nbproject/project.xml

require 'pathname'
require 'securerandom'

LibraryHeaders = %w{
  apa102c.h
  leds.h
  system.h
  time.h
  uart.h
  usb_helpers.h
}

LibrarySrc = %w{
  apa102c.c
  time.c
  uart.c
  usb_helpers.c
}

UsbHeaders = %w{
  usb.h
  usb_ch9.h
  usb_common.h
  usb_device.h
  usb_device_cdc.h
  usb_device_local.h
  usb_hal.h
  usb_hal_pic18.h
}

UsbSrc = %w{
  usb_device.c
  usb_device_cdc.c
}

class LogicalFolder
  attr_accessor :name
  attr_accessor :display_name
  attr_accessor :children

  def initialize(name, display_name)
    @name = name
    @display_name = display_name
    @children = []
  end

  def empty?
    @children.empty?
  end

  def <<(child)
    @children << child
  end

  def write(file, indent)
    file.puts "#{indent}<logicalFolder name=\"#{@name}\" displayName=\"#{@display_name}\" projectFiles=\"true\">"
    @children.each do |c|
      next_indent = indent + '  '
      if c.is_a?(String)
        file.puts "#{next_indent}<itemPath>#{c}</itemPath>"
      else
        c.write(file, next_indent)
      end
    end
    file.puts "#{indent}</logicalFolder>"
  end
end

def project_name(project_dir)
  project_dir.to_s.match(/(.+).X/)[1]
end

def generate_project_xml(project_dir)
  filename = project_dir + 'nbproject' + 'project.xml'

  # Generate the UUID or grab it from the file that is already there.
  if filename.exist?
    md = File.read(filename).match(/\w{8}-\w{4}-\w{4}-\w{4}-\w{12}/)
    uuid = md[0] if md
  end
  uuid ||= SecureRandom::uuid

  File.open(filename, 'w') do |f|
    f.write <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://www.netbeans.org/ns/project/1">
    <type>com.microchip.mplab.nbide.embedded.makeproject</type>
    <configuration>
        <data xmlns="http://www.netbeans.org/ns/make-project/1">
            <name>#{project_name(project_dir)}</name>
            <creation-uuid>#{uuid}</creation-uuid>
            <make-project-type>0</make-project-type>
            <c-extensions>c</c-extensions>
            <cpp-extensions/>
            <header-extensions>h</header-extensions>
            <asminc-extensions/>
            <sourceEncoding>ISO-8859-1</sourceEncoding>
            <make-dep-projects/>
        </data>
    </configuration>
</project>
EOF
  end
end

def get_logical_file_structure(project_dir)
  root = LogicalFolder.new('root', 'root')
  headers = LogicalFolder.new('HeaderFiles', 'Header Files')
  library_headers = LogicalFolder.new('f2', 'Libraries')
  usb_headers = LogicalFolder.new('f1', 'USB Framework')
  linker = LogicalFolder.new('LinkerScript', 'LinkerFiles')
  src = LogicalFolder.new('SourceFiles', 'Source Files')
  library_src = LogicalFolder.new('f1', 'Libraries')
  usb_src = LogicalFolder.new('usb', 'USB Framework')
  important = LogicalFolder.new('ExternalFiles', 'Important Files')

  project_dir.each_child(false) do |f|
    f = f.to_s
    case
    when LibraryHeaders.include?(f)
      library_headers << f
    when LibrarySrc.include?(f)
      library_src << f
    when UsbHeaders.include?(f)
      usb_headers << f
    when UsbSrc.include?(f)
      usb_src << f
    when f == 'Makefile'
      important << f
    when f.match(/.+\.h/)
      headers << f
    when f.match(/.+\.c/)
      src << f
    end
  end

  root << important
  root << headers
  headers << library_headers if !library_headers.empty?
  headers << usb_headers if !usb_headers.empty?
  root << linker
  root << src
  src << library_src if !library_src.empty?
  src << usb_src if !usb_src.empty?

  root
end

def generate_makefile(project_dir)
  File.open(project_dir + 'Makefile', 'w') do |f|
    f.write <<EOF
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
build: .build-post
.build-pre:
.build-post: .build-impl
clean: .clean-post
.clean-pre:
.clean-post: .clean-impl
clobber: .clobber-post
.clobber-pre:
.clobber-post: .clobber-impl
all: .all-post
.all-pre:
.all-post: .all-impl
help: .help-post
.help-pre:
.help-post: .help-impl
include nbproject/Makefile-impl.mk
include nbproject/Makefile-variables.mk
EOF
  end
end

def write_conf(file, pstar_type)
  file.write <<EOF
    <conf name="P-Star_#{pstar_type}" type="2">
      <toolsSet>
        <targetDevice>PIC18F#{pstar_type}</targetDevice>
        <platformTool>Simulator</platformTool>
        <languageToolchain>XC8</languageToolchain>
        <platform>3</platform>
      </toolsSet>
      <HI-TECH-COMP>
        <property key="warning-level" value="-3"/>
      </HI-TECH-COMP>
      <HI-TECH-LINK>
        <property key="additional-options-code-offset" value="0x2000"/>
        <appendMe value="--msgdisable=1311:off"/>
      </HI-TECH-LINK>
    </conf>
EOF
end

def generate_configurations_xml(project_dir, root)
  File.open(project_dir + 'nbproject' + 'configurations.xml', 'w') do |f|
    f.write <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<configurationDescriptor version="62">
EOF

    root.write(f, '  ')

    f.write <<EOF
  <sourceRootList>
    <Elem>.</Elem>
  </sourceRootList>
  <projectmakefile>Makefile</projectmakefile>
  <confs>
EOF

    write_conf(f, '25K50')
    write_conf(f, '45K50')

    f.write <<EOF
  </confs>
</configurationDescriptor>
EOF
  end
end

def generate_project(project_dir)
  puts "Generating for #{project_name(project_dir)}..."
  nbproject_dir = project_dir + 'nbproject'
  nbproject_dir.mkdir if !nbproject_dir.exist?
  generate_makefile(project_dir)
  generate_project_xml(project_dir)
  root = get_logical_file_structure(project_dir)
  generate_configurations_xml(project_dir, root)
end

def generate_all
  Dir.chdir(File.dirname(__FILE__))
  Pathname::glob("*.X").each do |project_dir|
    generate_project(project_dir)
  end
end

generate_all
