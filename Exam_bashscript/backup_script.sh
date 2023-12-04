#!/bin/bash

# Check if the user has entered at least one directory
if [ $# -eq 0 ]; then
    echo "Zero arguments, please use as following: $0 [directory1] [directory2] [directory3] [...]"
    exit 1
fi

# Set the backup directory
backup_directory="backups"

# If the backup directory doesn't exist, create it
if [ ! -d "$backup_directory" ]; then
   mkdir "$backup_directory"
fi

# Loop through each specified directory
for directory in "$@"; do
   # Check if the directory exists
   if [ -d "$directory" ]; then
      # Create a backup file in the format backup_<directory>_<date>.tar.gz
      backup_file="backup_$(basename "$directory")_$(date +%Y%m%d).tar.gz"
      
      # Use the tar command to create a compressed file
      tar -czf "$backup_directory/$backup_file" "$directory"
      
      # Check the exit status of the tar command
      if [ $? -eq 0 ]; then
         echo "Backup file of $directory was successfully created: $backup_file"
      else
         echo "Backup file of $directory failed to be created"
      fi
      
   else 
      echo "Error: The directory '$directory' doesn't exist."
   fi
done
