# Filter Design

For all images the original image header will be copied to the result, and the RGB values will be read pixel per pixel. 
Then, the resulting values will be copied into the resulting image.

## Redscale

Obtain red, green and blue values for each pixel, then proceed by adding an arbitrary value to the current red value, for this project the value will be 60.

If the sum of the current red value and 60 is higher than 255 then set the red value to 255, else, add 60 to the current rgb value. 

Formula: Red value + 60.

If the current values are 200, 10, 60 then the result would be 255, 70, 120.

## Increase Brightness

Obtain red, green and blue values for each pixel, then proceed by adding an arbitrary value to the current RGB (Red, green or blue) value, for this project the value will be 50.

If the sum of the current red, green or blue value and 50 is higher than 255 then set the corresponding value to 255, else, add 50 to it. 

Formula: red, green or blue values + 50.

If the current values are, 105, 100, 235 then the result would be 155, 150, 255.

## Negative

Obtain red, green and blue values for each pixel, then proceed by calculating the new value by subtracting the current value to 255. 

Formula: 255 - red, green or blue value.

If the current values are 50, 180, 135 then the result of the subtraction for each value would be, 205, 75, 120.

## Grayscale

Take the sum of the current red, green and blue values, divide it by three, and set all the values to the closest integer to the calculation. (CS101, n.d)

Formula: red, green and blue values / 3.

If the current values are 100, 255, 255 the sum of these would be 610, which divided by three is roughly 203.

## Pixelated

Read a pixel's data, the copy the data to the next pixel, jump to the next pixel and repeat.

Formula: pixelN+1 = pixelN.

If the first pixel's data is 25, 55, 140 then the data for the second pixel will be 25, 55, 140. 

Then move to the next pixel, to avoid repeating the same pixel values on all the image.

## References

[CS101 - Grayscale](https://web.stanford.edu/class/cs101/image-6-grayscale-adva.html)
