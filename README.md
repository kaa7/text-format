# Text format tool written in C

## Build

Build with **make**.

## Usage

Run with **./format_text \<operations> <input_file> <output_file>**.

Supports the following operations, in the following format :
* Line wraping : **W max_line_length**

  Wraps the entire input file so that each line is at most max_line_length long. Does not break
  lines in the middle of a word.
* Center alignment : **C [start_line [end_line]]**

  Aligns lines to the center in the specified interval.
* Left alignment : **L [start_line [end_line]]**
  
  Aligns lines to the left in the specified interval.
* Right alignment : **R [start_line [end_line]]**
  
  Aligns lines to the right in the specified interval.
* Justified alignment : **J [start_line [end_line]]**
  
  Justifies lines in the specified interval, ie. adds spaces so that the text falls flush with both left and right margins.
* Paragraph indenting : **P indent_length [start_line [end_line]]**
  
  Indents the first line of a paragraph in the specified interval by the specified amount.
* List creation : **I list_type special_character [start_line [end_line]]**
  
  list_type can be : 
  * n : ordered list
  * a / A : alphabetical list (lower or upper case)
  * b : bullet list
 special_character is the next character after the numerical/aphabetical index or the character
 used as a bullet point.
* Ordered list creation : **O list_type special_character ordering [start_line [end_line]]**

  Same as the normal lists, but it sorts the lines in the specified interval.
ordering can be :
  * a : lexicographical order
  * z : reverse lexicographical order

The first letter of an operation is case-insensitive.

Parameters between square brackets are optional. If unspecified, start_line defaults to the first
line of the input file, and end_line defaults to the last line of the file.

Multiple commands can be given at once, eg. **'W 80, r'**, but only the first 10 operations will pe applied (actual number is defined in utils.h).



## Examples :
Applying **W 60** on:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo. Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi mauris massa, aliquam sed eros in, fringilla accumsan neque. Quisque blandit lobortis purus vitae gravida.
 
Morbi sit amet euismod leo. Quisque in hendrerit turpis, ac fringilla ante. Sed id mi bibendum, scelerisque arcu vel, rutrum nibh.
```
yields
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit.
Integer elementum, ipsum sit amet vulputate semper, orci
justo condimentum felis, eu lobortis metus quam ac mauris.
Mauris sed pharetra leo. Morbi mollis nunc eu velit
tincidunt ullamcorper. Vestibulum finibus tellus ac lobortis
porttitor. Integer a lacus nisi. Morbi mauris massa, aliquam
sed eros in, fringilla accumsan neque. Quisque blandit
lobortis purus vitae gravida.
 
Morbi sit amet euismod leo. Quisque in hendrerit turpis, ac
fringilla ante. Sed id mi bibendum, scelerisque arcu vel,
rutrum nibh.
```
Applying **C** on:
```
Lorem ipsum
 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris massa, aliquam sed eros in, fringilla accumsan neque.
Quisque blandit lobortis purus vitae gravida.
```
yields:
```
                            Lorem ipsum
 
 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
 felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
   Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
 finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
   mauris massa, aliquam sed eros in, fringilla accumsan neque.
           Quisque blandit lobortis purus vitae gravida.
```
Applying **L** on:
```
  Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
  Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris massa, aliquam sed eros in, fringilla accumsan neque.
         Quisque blandit lobortis purus vitae gravida.
```
yields:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris massa, aliquam sed eros in, fringilla accumsan neque.
Quisque blandit lobortis purus vitae gravida.
```

Applying **R** on:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris massa, aliquam sed eros in, fringilla accumsan neque.
Quisque blandit lobortis purus vitae gravida.
```
yields:
```
  Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
 felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
      Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
 finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
      mauris massa, aliquam sed eros in, fringilla accumsan neque.
                     Quisque blandit lobortis purus vitae gravida.
```
Applying **J** on:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris massa, aliquam sed eros in, fringilla accumsan neque.
Quisque blandit lobortis purus vitae gravida.
 
    Morbi sit amet euismod leo. Quisque in hendrerit turpis, ac
fringilla ante. Sed id mi bibendum, scelerisque arcu vel,
rutrum nibh.
```
yields:
```
Lorem  ipsum dolor sit amet, consectetur adipiscing elit.  Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis,  eu lobortis metus quam ac mauris. Mauris sed pharetra leo.
Morbi  mollis  nunc  eu velit  tincidunt  ullamcorper.  Vestibulum
finibus  tellus ac lobortis porttitor. Integer a lacus nisi. Morbi
mauris  massa,  aliquam  sed  eros in,  fringilla accumsan  neque.
Quisque blandit lobortis purus vitae gravida.
 
Morbi  sit  amet  euismod  leo. Quisque in  hendrerit  turpis,  ac
fringilla   ante.  Sed  id  mi  bibendum,  scelerisque  arcu  vel,
rutrum nibh.
```
Applying **P 4** on:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris.
 
Mauris sed pharetra leo.
 
Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi.
```
yields:
```
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
elementum, ipsum sit amet vulputate semper, orci justo condimentum
felis, eu lobortis metus quam ac mauris.
 
    Mauris sed pharetra leo.
 
    Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum
finibus tellus ac lobortis porttitor. Integer a lacus nisi.
```

Applying **I n .** on:
```
apples
oranges
cherries
```
yields:
```
1. apples
2. oranges
3. cherries
```
Applying **I a )** on:
```
apples
oranges
cherries
```
yields:
```
a) apples
b) oranges
c) cherries
```
Applying O b - z on:
```
Monica
Erica
Rita
Tina
Sandra
Mary
Jessica
```
yields :
```
- Tina
- Sandra
- Rita
- Monica
- Mary
- Jessica
- Erica
```

