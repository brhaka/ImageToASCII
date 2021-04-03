# ImageToASCII

[![License](https://img.shields.io/github/license/brhaka/ImageToASCII)](https://github.com/brhaka/ImageToASCII/blob/master/LICENSE)
[![Size!](https://img.shields.io/github/languages/code-size/brhaka/ImageToASCII)](https://github.com/brhaka/ImageToASCII)

[![GitHub stars](https://img.shields.io/github/stars/brhaka/ImageToASCII.svg?style=social&label=Star)](https://github.com/brhaka/ImageToASCII)
[![GitHub watch](https://img.shields.io/github/watchers/brhaka/ImageToASCII.svg?style=social&label=Watch)](https://github.com/brhaka/ImageToASCII)

## Usage

`ImageToASCII` runs on the Command-Line.
You must provide a path to the image you want to convert. You can do this by passing it as a Command-Line Argument (`./ImageToASCII "./image.png"`). In the case where no argument is passed, ImageToASCII will prompt you to write the image path on the command-line.

Another input that `ImageToASCII` requires is the `Image Resize Factor`. You can enter a value between `1` and `50`. The image will be resized according to the entered value. E.g.: With a resize factor of 10, a 3840x2160 (pixels) image becomes a 384x216 (characters) ASCII art.

There are also other inputs ImageToASCII will ask you, such as wether you want to store the path to the image for later use and also wether you want to use the stored path (if previously stored).

The ASCII art is saved to a file named `ascii.brk`. The extension is symbolic, but since NotePad has a limit of 1024 characters per line, to avoid confusion, we do not save it to a .txt file. You can open the `.brk` file with any text editor. Personally, I use [NotePad++](https://github.com/notepad-plus-plus/notepad-plus-plus).

Since the program has no control over which font the ASCII art is being visualized, a whitespace is inserted after each character. E.g.: '@' becomes '@ '

<sub>*Please have in mind that the larger your ASCII art is, the more detailed it can be. It will be also heavier. E.g.: 1 character = 1 byte, so a 384x216 ASCII art weights 82.944 bytes PLUS whitespaces between columns. Total of 165.888 bytes.*</sup>

## Installation

ImageToASCII is compiled to a single file, for easier use. If you want to run it on an UNIX OS, like **Linux** and **MacOS**, you should download the `ImageToASCII` file. In case you want to run it on **Windows** x64 or x86, download the `ImageToASCII.exe` file. You can start your download at the [Releases](https://github.com/brhaka/ImageToASCII/releases) section.

To start the program, all you need to do is execute it via command-line: (`./ImageToASCII "./image.png"`) or (`./ImageToASCII.exe "./image.png"`).

### Branches

The **[master](https://github.com/brhaka/ImageToASCII/tree/master)** branch contains the most recent stable release source code. The **[development](https://github.com/brhaka/ImageToASCII/tree/development)** branch contains the current development source code. It may be unstable.

### Compilation

It's also possible to download the source code and compile it yourself. First, you must clone or fork this repository into an empty directory. Then, via command-line, you can run the following commands:

`make UNIX` will compile the **UNIX** version of the program. The output file is named `ImageToASCII`. This command uses `gcc`.

`make WIN` will compile the **Windows** (x64 and x86) version of the program. The output file is named `ImageToASCII.exe`. This command uses **mingw**.

The `make`, `make all`, `make re` and `make ImageToASCII` commands will compile both **UNIX** and **Windows** versions of the program.

## Features

* Supports JPG, JPEG, PNG, TGA, BMP, PSD, HDR, PIC
* Works with **any** image resolution
* Clean and detailed ASCII arts
* **UNIX** and **Windows** versions
* Lightweight

## Showcase

![Beliaikin](https://user-images.githubusercontent.com/32342284/113486110-00477900-94a9-11eb-82f8-b0927eb04f75.jpg)
![Antelope Close-Up](https://user-images.githubusercontent.com/32342284/113486115-03426980-94a9-11eb-9d07-807445e3e608.jpg)
![Leitisvatn](https://user-images.githubusercontent.com/32342284/113486120-05a4c380-94a9-11eb-8edd-a9513ed0a3c4.jpg)
![Girl Holding Leaf](https://user-images.githubusercontent.com/32342284/113486484-06d6f000-94ab-11eb-9cda-6aa50a31dc41.jpg)

*Images by [pexels.com](https://www.pexels.com/collections/imagetoascii-vk9vgay/) and [Eirik Sørstrømmen](https://500px.com/photo/122484453/the-cliffs-of-leitisvatn-by-eirik-sorstrommen)*

## Contributing
**Like what you see?** Please, feel free to fork this repository, and make any change you like. If you
want to propose a nice feature, please create a separate branch on your fork,
named after the feature you want to implement, then make a pull request from that
branch. Thank you!
