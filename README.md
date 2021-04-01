# ImageToASCII

[![License](https://img.shields.io/github/license/brhaka/ImageToASCII)](https://github.com/brhaka/ImageToASCII/blob/master/LICENSE)
[![Size!](https://img.shields.io/github/languages/code-size/brhaka/ImageToASCII)](https://github.com/brhaka/ImageToASCII)

[![GitHub stars](https://img.shields.io/github/stars/brhaka/ImageToASCII.svg?style=social&label=Star)](https://github.com/brhaka/ImageToASCII)
[![GitHub watch](https://img.shields.io/github/watchers/brhaka/ImageToASCII.svg?style=social&label=Watch)](https://github.com/brhaka/ImageToASCII)

## Usage

`ImageToASCII` runs on the Command-Line.
You must provide a path to the image you want to convert. You can do this by passing it as a Command-Line argument (`./ImageToASCII "./image.png"`). In the case where no argument is passed, ImageToASCII will prompt you to write the image path on the command-line.

Another input that `ImageToASCII` requires is the `Image Resize Factor`. You can enter a value between `1` and `50`. The program will resize the image according to the entered value. E.g.: With a resize factor of 10, a 3840x2160 (pixels) image becomes a 384x216 (characters) ASCII art.

There are also other inputs ImageToASCII will ask you, such as wether you want to store the path to the image for later use and also wether you want to use the stored path (if any).

The ASCII art is saved to a file named `ascii.brk`. The extension is symbolic, but since NotePad has a limit of 1024 characters per line, to avoid confusion, we do not save it to a .txt file. You can open the `.brk` file with [NotePad++](https://github.com/notepad-plus-plus/notepad-plus-plus) or your favorite text editor.

Since the program has no control over which font the ASCII art is being visualized, a whitespace is inserted after each character. E.g.: '@' becomes '@ '

<sub>*Please have in mind that the larger your ASCII art is, the more detailed it can be. It will be also heavier. E.g.: 1 character = 1 byte, so a 384x216 ASCII art weights 82.944 bytes PLUS whitespaces between columns.*</sup>

## Installation

[ImageToASCII](https://github.com/brhaka/ImageToASCII/releases/download/1.0/ImageToASCII) is the only file you need to run the program.
After downloading it, you can run it using the command-line (`./ImageToASCII "./image.png"`).

## Features

* Supports JPG, JPEG, PNG, TGA, BMP, PSD, HDR, PIC
* Works with **any** image resolution
* Clean and detailed ASCII arts
* Lightweight

## Showcase

![Lemur GIF](https://github.com/brhaka/ImageToASCII/blob/master/gif/lemur_demo.gif)

### Contributing
**Like what you see?** Please, feel free to fork this repository, and make any change you like. If you
want to propose a nice feature, please create a separate branch on your fork,
named after the feature you want to implement, then make a pull request from that
branch. Thank you!
