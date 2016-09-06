#!/usr/bin/bash

# This Bash script creates a ZIP file for each example that is
# suitable for being uploaded to the MPLAB XPress IDE.

for project in usb-to-serial; do
  git archive -o $project.zip HEAD $project.X
done
