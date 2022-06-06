# Product design

The product design consists of the following parts:

1. A virtualized device to perform hardware simulation. By doing this, the device can capture, transform, and filter photos or images. Finally, these filtered images/photos will be sent to a virtual environment that uses Ubuntu as its operating system.

2. A driver that works on Ubuntu. This driver will allow any process in the operating system to access the device.

3. Program that allows the user to apply filters to the image to verify the correct operation of the driver and the device uploaded to the Github repository.

4. Protocol that allows communication between the virtualized device and the driver.

5. Tests to verify the correct operation of the device and the filters.

![Product Design](Product_design.jpg)

Image 1: Design of the product

## Implementation

--------------------------------------------------------------------------------

### Registers

--------------------------------------------------------------------------------

To implement the PCI device (the camera) the following registers where created:

1. current_status: Stores the current status of the device. It can have the following values:

        0x0: the device is shutdown.
        0x1: the device is on.
        0x2: the device is applying a filter to an image.
        0x3: the device received an error.

2. filter_to_be_applied: Stores the filter that is going to be applied to the image. It can have the following values:

        0x0: no filter is being applied.
        0x1: negative filter.
        0x2: increase brightness filter.
        0x3: red coloration filter.
        0x4: grayscale filter.
        0x5: pixelated filter.

3. size_of_bmp: Stores the size of the bmp archive.

4. day: Stores the day in which the image was modified.

5. year: Stores the year in which the image was modified.

6. hour: Stores the hour in which the image was modified.

7. cmd: This register will be later modified to help write the bytes of the bmp archive to the buffer.

8. buffer: Stores the bytes of the bmp archive.

[Return to README](../README.md)
