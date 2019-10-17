# mBEDed One
 
A upgrade to Arduino UNO while keeping the same core features intact.

# Table of contents
* [Microcontroller](#microcontroller)
* **[How to install](#how-to-install)**
  - [Boards Manager Installation](#boards-manager-installation)
  - [Manual Installation](#manual-installation)
* **[Getting started](#getting-started)**
  - [with mBEDed One Board](#with-mbeded-one-board)
  - [with bare minimum µC or custom board](#with-bare-minimum-µC-or-custom-board)
* [Wiring reference](#wiring-reference)
* **[Pinout](#pinout)**

## Microcontroller
* LGT8F328D

## How to install
#### Boards Manager Installation
This installation method requires Arduino IDE version 1.6.4 or greater.
* Open the Arduino IDE.
* Open the **File > Preferences** menu item.
* Enter the following URL in **Additional Boards Manager URLs**:
    ```
    https://mbeded.github.io/mBEDed-One/package_mBEDed_mBEDed-One_index.json
    ```
* Separate the URLs using a comma ( **,** ) if you have more than one URL
* Open the **Tools > Board > Boards Manager...** menu item.
* Wait for the platform indexes to finish downloading.
* Scroll down until you see the **mBEDed One** entry and click on it.
* Click **Install**.
* After installation is complete close the **Boards Manager** window.

#### Manual Installation
Click on the "Download ZIP" button. Extract the ZIP file, and move the extracted folder to the location "**~/Documents/Arduino/hardware**". Create the "hardware" folder if it doesn't exist.
Open Arduino IDE, and a new category in the Board menu called "mBEDed One" will show up.

## Getting started 
Ok, so you're downloaded and installed mBEDed One, but how to get started? Here's a quick start guide:

#### with mBEDed One Board
* Hook up your mBEDed One just as Arduino Uno.
* Open the **Tools > Board** menu item, and select **mBEDed One**.
* Select **mBEDed One Board** varient.
* Then select the correct serial port under the **Tools** menu, and click the **Upload** button.

#### with bare minimum µC or custom board
* Hook up your microcontroller as shown in the [pinout diagram](#pinout).
  - If you're not planning to use the bootloader (uploading code using a USB to serial adapter), the FTDI header and the 100 nF capacitor on the reset pin can be omitted.
* Open the **Tools > Board** menu item, and select **mBEDed One**. 
* Select **Generic LGT8F328D** varient.
* If you are using external programmer then, select what kind of programmer you're using under the **Programmers** menu.
* Hit **Burn Bootloader**. As an LED is connected to pin 13, it should flash twice every second.* Now that the bootloader burnt, you can upload your code in two ways (as no fuse settings is required for mBEDed One to set):
  - Disconnect your programmer tool, and connect a USB to to on-board connector to the microcontroller, like shown in the [pinout diagram](#pinout). Then select the correct serial port under the **Tools** menu, and click the **Upload** button. If you're getting some kind of timeout error, it means your RX and TX pins are swapped, or your auto reset circuity isn't working properly (the 100 nF capacitor on the reset line).
  - Keep your programmer connected, and hold down the `shift` button while clicking **Upload**. This will erase the bootloader and upload your code using the programmer tool.

Your code should now be running on the microcontroller!

## Wiring reference
To extend this core's functionality a bit further, We've added a few missing Wiring functions to this hardware package. As many of you know Arduino is based on Wiring, but that doesn't mean the Wiring development isn't active. These functions is used as "regular" Arduino functions, and there's no need to include an external library.<br/>
I hope you find this useful, because they really are!

### Function list
* DAC Output Function

### For further information please view the Wiring reference inside library!


## Pinout

### LGT8F328D
Since there are no standardized pinout for this chip family, We've created one. We've tried to make it as simple and logical as possible. This pinout makes great sense if you're getting this [mBEDed One Board](https://mBEDed.Systems) from us. The standard LED pin is assigned to Arduino pin 13, and will blink twice if you hit the reset button.