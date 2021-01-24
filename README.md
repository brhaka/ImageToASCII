# ImageToASCII

Simple ImageToASCII converter written in C

## Usage

`ImageToASCII` runs on the Command-Line.
You must provide a path to the image which will be converted. You can do so by passing it as a Command-Line argument (`./ImageToASCII.exe "./image.png"`). In the case where no argument is passed, ImageToASCII will prompt you to write the image path on the command-line.

Another input `ImageToASCII` requires is the `Image Resize Factor`. You can enter a value between `1` and `10`. The program will resize the image according to the value entered (`image_size` / `resize_factor`).
