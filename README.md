# eye-detection
a collaborative project with other Marquette Biocomputing majors to build a eye detection application

## EyeDetection

The main subsystem used to parse a .bin file representing a 2-dimensional image, run an edge detection algorithm, run a circle detection algorithm to find the pupil, and return via a .csv file the coordinates of that circle

## EdgeDetection

Runs a Sobel Filter on a 2D Image Object and returns a threshold evaluated bit-map

## CircleDetection

Runs the Hough transform algorithm on a 2D bit-map of the edges on an image of an eye to detect the pupil

## gui

A MATLAB GUIDE create UI to input an image file path, an expected output path of the coordinates, and call the main subsystem. Transforms a jpeg image into a .bin file representing the grayscale pixel values of each pixel.

## Test resources

Shared images, files, and more to test our subsystems
