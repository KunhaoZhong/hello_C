#!/bin/bash


# The script use "imagemagick" command "convert" to rescale all the images in .jpg to 10% and convert them to .png
cd images || exit 1
for image in *.jpg 
do
  #echo `basename $image .jpg`.png
  convert -resize 10% $image `basename $image .jpg`.png
  rm $image
done
