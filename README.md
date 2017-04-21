tdrpg-tools
===========

A set of tools for the tdrpg-haxe project (ie, [Defender's Quest 2](http://www.defendersquest.com/2/))

These are just internal tools and are incredibly poorly documented because 99% of them are throwaway things I only use myself. Please don't email me asking how to use them, but if you're brave you're free to try getting my janky scripts to work for your own purposes.

# TileProcess

TileProcess lets an artist create a "sparse" tileset, then does all the boring scut-work of generating tile connection permutations for final use in the game.

It also creates a "Quick Brown Fox" tiling test that uses every tile connection so the artist can see how they're doing.

TileProcess can be scripted to generate arbitrary output. So you can use it for processing and re-arranging tilesets as well as compositing.

![](https://raw.githubusercontent.com/larsiusprime/tdrpg-tools/master/TileProcess/LOOKATME.png)


# PathFindingTest (moved!)
PathFindingTest has now become an official [HaxeFlixel](http://github.com/HaxeFlixel) demo, [Heatmap Pathfinding](https://github.com/HaxeFlixel/flixel-demos/tree/dev/Flixel%20Features/HeatmapPathfinding)

(The version in this repo is now obsolete)

A simple test of the [many-to-one pathfinding method](http://gamasutra.com/blogs/TylerGlaiel/20121007/178966/Some_experiments_in_pathfinding__AI.php)

![](http://raw.github.com/larsiusprime/tdrpg-tools/master/PathFindingTest/screenshot.png)


# Animator (moved!)
Animator has been officially accepted into the [HaxeFlixel](http://github.com/HaxeFlixel) project @ [flixel-editors](http://github.com/HaxeFlixel/flixel-editors)! 

I'm permanently moving Animator over there to avoid accidentally committing to the wrong place. 

I'll still keep this repo around for tools that HaxeFlixel isn't interested in.
