#!/bin/bash

# Set the download URL and output file name
url="https://cdn.discordapp.com/attachments/866555970050457650/1123086671257272420/assets.zip"
output_file="assets.zip"

# Set the Git repository URL
repository_url="https://github.com/itzilly/MobSlayer.git"

# Set the target directory name
target_directory="MobSlayer"

# Download the ZIP file
curl -o "$output_file" "$url"

# Extract the contents of the ZIP file
unzip "$output_file"

# Clone the Git repository
git clone "$repository_url" "$target_directory"

# Move the extracted "assets" folder into the "MobSlayer" directory
mv assets "$target_directory/assets"

# Remove the ZIP file
rm "$output_file"
