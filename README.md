# ImageToASCII

[![License](https://img.shields.io/github/license/brhaka/ImageToASCII?style=for-the-badge)](https://github.com/brhaka/ImageToASCII/blob/master/LICENSE)
[![Release](https://img.shields.io/github/v/release/brhaka/ImageToASCII?color=%234DC820&style=for-the-badge)](https://github.com/brhaka/ImageToASCII)
[![Size](https://img.shields.io/github/languages/code-size/brhaka/ImageToASCII?style=for-the-badge)](https://github.com/brhaka/ImageToASCII)

[![GitHub stars](https://img.shields.io/github/stars/brhaka/ImageToASCII.svg?style=social&label=Star)](https://github.com/brhaka/ImageToASCII)

## Usage

`ImageToASCII` runs on the Command-Line.
You must provide a path to the image you want to convert. You can do this by passing it as a Command-Line argument (`./ImageToASCII "./image.png"`). In the case where no argument is passed, ImageToASCII will prompt you to write the image path on the command-line.

Another input that `ImageToASCII` requires is the `Image Resize Factor`. You can enter a value between `1` and `50`. The image will be resized according to the entered value. E.g.: With a resize factor of 10, a 3840x2160 (pixels) image becomes a 384x216 (characters) ASCII art.

There are also other inputs ImageToASCII will ask you, such as wether you want to store the path to the image for later use and also wether you want to use the stored path (if previously stored).

The ASCII art is saved to a file named `ascii.brk`. The extension is symbolic, but since NotePad has a limit of 1024 characters per line, to avoid confusion, it is not saved as a `.txt` file. You can open the `.brk` file with any text editor. Personally, I use [NotePad++](https://github.com/notepad-plus-plus/notepad-plus-plus).

Since the program has no control over which font the ASCII art is being visualized, a whitespace is inserted after each character. E.g.: '@' becomes '@ '

<sub>*Please have in mind that the larger your ASCII art is, the more detailed it can be. It will be also heavier. E.g.: 1 character = 1 byte, so a 384x216 ASCII art weights 82.944 bytes PLUS whitespaces between columns. Total of 165.888 bytes.*</sup>

## Installation

ImageToASCII is compiled to a single file, for easier use. If you want to run it on an **UNIX** Operating System, like **Linux** and **MacOS**, you should download the `ImageToASCII-Linux` or `ImageToASCII-MacOS` file. In case you want to run it on **Windows** x64 or x86, download the `ImageToASCII-Windows_x86_x64.exe` file. You can start your download at the [Releases](https://github.com/brhaka/ImageToASCII/releases) section.

To start the program, all you need to do is execute it via command-line: (`./ImageToASCII "./image.png"`) or (`./ImageToASCII.exe "./image.png"`).

### Branches

The **[master](https://github.com/brhaka/ImageToASCII/tree/master)** branch contains the most recent stable release source code. The **[development](https://github.com/brhaka/ImageToASCII/tree/development)** branch contains the current development source code. It may be unstable.

### Compiling

It's also possible to download the source code and compile it yourself. First, you must clone or fork this repository into an empty directory. Then, via command-line, you can run the following commands:

`make UNIX` will compile the **UNIX** version of the program. The output file is named `ImageToASCII`. This command uses `gcc`. In order to execute it on Linux, it must be compiled on **Linux** and in order to execute it on MacOS, it must be compiled on **MacOS**.

`make WIN` will compile the **Windows** (x64 and x86) version of the program. The output file is named `ImageToASCII.exe`. This command uses **mingw**.

The `make`, `make all`, `make re` and `make ImageToASCII` commands will compile both **UNIX** and **Windows** versions of the program.

To compile a version that won't use ANSI colors on the output, add `USE_COLORS=0` to your `make *` command. E.g: `make WIN USE_COLORS=0`

## Features

* Supports JPG, JPEG, PNG, TGA, BMP, PSD, HDR, PIC
* Works with **any** image resolution
* Clean and detailed ASCII arts
* **Linux**, **MacOS** and **Windows** versions
* Lightweight
* Open Source

## Showcase

### High character count

![Beliaikin](https://user-images.githubusercontent.com/32342284/114232473-d7752700-9973-11eb-9889-dc30f1bb69d8.jpg)
![Antelope Close-Up](https://user-images.githubusercontent.com/32342284/114233077-b2cd7f00-9974-11eb-932e-b95f23102268.jpg)
![Leitisvatn](https://user-images.githubusercontent.com/32342284/114232421-c5938400-9973-11eb-8f8b-ac16a543ade0.jpg)
![Girl Holding Leaf](https://user-images.githubusercontent.com/32342284/114232397-b90f2b80-9973-11eb-9958-1dd4f8296875.jpg)

### Low character count

![Pear Low](https://user-images.githubusercontent.com/32342284/114232801-5d916d80-9974-11eb-88f5-a94218a8a622.jpg)
![Antelope Close-Up Low](https://user-images.githubusercontent.com/32342284/114232569-f673b900-9973-11eb-874c-675369ebe6ea.jpg)

*Images by [pexels.com](https://www.pexels.com/collections/imagetoascii-vk9vgay/) and [Eirik Sørstrømmen](https://500px.com/photo/122484453/the-cliffs-of-leitisvatn-by-eirik-sorstrommen)*

## Contributing
**Like what you see?** Please, feel free to fork this repository, and make any change you like. If you
want to propose a nice feature, please create a separate branch on your fork,
named after the feature you want to implement, then make a pull request from that
branch. Thank you!
