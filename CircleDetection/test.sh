#!/bin/bash
image_filename="eye_test_image4.jpg.bin"
height=90
width=130
minRadius=5
maxRadius=100

(./test.exe $image_filename $height $width $minRadius $maxRadius)
