#dqsprite

This is a bare-bones texture packing tool specifically designed for Defender's Quest's use case.

##Usage 1: "hero" characters

```
dqsprite in.png out.png 128 128 192 192
```

That will take a sprite-sheet that has uniform cells of size 192x192, crop each cell to the minimum area, 
scale them down to fit in a 128x128 cell, remove any duplicates, and spit out a packed atlas and xml file.

##Usage 2: "generic" (ie re-colorizable) characters

```
dqsprite in.png out.png 128 128 192 192 layers.xml
```

This is for a sprite that you want to use with tdrpg's stacked layer system. You need to provide a file like this, too:

```xml
<layer name="base"/>
<layer name="skin"         color="0xFF0000"/>
<layer name="skin_hilight" color="0x00FF00"/>
<layer name="pants"        color="0x0000FF"/>
<layer name="hair"         color="0xFF00FF"/>
<layer name="hair_hilight" color="0xFFFF00"/>
<layer name="eyes"         color="0x00FFFF"/>
```

NOTE: The original sprite should NOT be anti-aliased if you want this to work well. 

The tool will split the file into layers. First, it looks for layer definitions in the xml that have been assigned 6 special colors:

0xFF0000 (RED)
0x00FF00 (GREEN)
0x0000FF (BLUE)
0xFFFF00 (YELLOW)
0x00FFFF (CYAN)
0xFF00FF (MAGENTA)

Then it will look for pixel values in the image that are monochromatic tints of that value. So the 0x0000FF layer will match any
values like 0x000080, 0x000001, 0x0000F0, but not 0x0080F0 or 0x0101FF. It then grabs these as a separate layer and converts it to grayscale,
then runs the full duplicate-culling and texture packing operation on it. So, you create a monochrome layer and shade it, with full white representing
the area you want to match the user color you're assignging to that layer in the tdrpg engine, and all other values representing darker tints. Then you kill
a color channel or two so you can color-code it for asset packing.

The tool can only do this special trick with the above six colors. It can, however, do a pixel-perfect match of any greyscale value that isn't black.

So it can match:

0xFFFFFF
0x808080
0x404040

And it will separate that out as its own layer. It will ONLY grab pixels that exactly match that value, so you don't get to grab shaded regions like
you can with the color channel method.

This tool is kind of a hack but whatever. The asset data is spits out matches the "Sparrow" texture packer format that is one of many HaxeFlixel can read from.

