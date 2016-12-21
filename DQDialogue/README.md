# Blocks

The parser looks for "blocks", text that is:

* Surrounded by a full white line on either side (or beginning/end of the document)
* Connected by single line breaks
* Has a keyword and parameters on the first line

Blocks look like this:

```
Keyword parameter parameter
This is a line
This is another line
This is all block 1
```

```
Keyword parameter
This is block 2
```

```
Keyword
This is block 3
This is still block 3
```

# Rules

* A full white line (two line breaks, or the end of the document) always terminates a block
    * Don’t worry about running to the next "page" in a word processor, as long as extra unintended line breaks don’t show up when exported as a text file it’s okay

* The first line in a block is the KEYWORD line
    * Keywords are matched against an enumerated list
    * Keywords are case insensitive
    * If a keyword is matched, it will treat everything else left over as parameters separated by spaces
    * All punctuation and special characters are ignored and stripped from the keyword line
    * If a keyword is not matched, it assumes every word on the keyword line is to be treated as a speaker’s name and that the block is itself a speech line

* Every line in a block after the first is a CONTENT line
    * How these are parsed varies a bit depending on the keyword
    * Generally, they’re all treated as individual single-line text "beats"
    * For instance, these two examples yield identical results:

**Example 1:**

```
Terevan
Some words!
Some more words!
```

**Example 2:**
```
Terevan
Some words!

Terevan
Some more words!
```

* Every word in the keyword line left over after the keyword has been matched and subtracted are treated as PARAMETERS.
    * Parameters are specific to the block -- see documentation below for details
    * Parameters can also be supplied as additional lines provided immediately after the keyword line, each beginning with a sub-keyword that matches the name of the parameter (case insensitive).

**Example 1:**

```
Town
Town Paris
Pearl 7
Section equip
```
**Example 2:**
```
Town Paris 7 equip
```
**Example 3:**
```
Town Paris
Pearl 7
Section equip
```
**Example 4:**

```
The Many Voices of the Hollow Mind annoyed
I am annoyed
```

**Example 5:**

```
The Many Voices of the Hollow Mind
Emote annoyed
I am annoyed
```

  * You may provide parameters on the keyword line, or on their own lines with a matching sub-keyword name.
    * If provided on the keyword line, *order always matters*.
    * If provided as separate lines, *order does not matter*. 
    * In examples 1-3 the values "Paris", “7”, and “equip” are matched to `<Town>`, `<Pearl>`, and `<Section>` parameters. The parser will first check to see if there are any parameters on the keyword line, and if it doesn’t find them there, will check for named parameter sub-lines.
    * For speech lines where the speaker’s name includes spaces, parameters supplied on the keyword line will not be properly parsed unless you first define the name using the NAMES block at the beginning of the document.

# Keywords

The exhaustive list of keywords:

* Begin
* End
* Names
* Plaintext
* Narrator
* Comment
* Tutorial
* Intro
* Newgame
* Battle
* Outro
* Overworld
* Rewards
* Party
* `<Speech>`

Here is the complete documentation for each keyword and its parameters, with usage directions and examples for each:

## BEGIN

Starts a new scene. Expects an "End" block before the next “Begin” block. Any blocks that are not properly sandwiched between a “Begin” and “End” block will be ignored.

**Usage:**
```
Begin
<Title of the scene>
```

**Example:**
```
Begin
Where Am I?
```
**Notes:**
Because anything after a matched keyword is treated as a parameter, and BEGIN uses no parameters, you can use "Begin scene" as a valid alias for “Begin” because “scene” will just be ignored.

**Advanced:**

After the first line, you can set various metadata properties for a cutscene. Order doesn’t matter so long as they appear after the title line:

* PLOTLINE
* BACKGROUND
* MUSIC
* DEMO MUSIC
* ACT
* SCENE
* FOREGROUND LEFT
* FOREGROUND RIGHT

"PLOTLINE" lets you string various scenes together in the game triggers. If you don’t provide this value, it automatically assigns this scene to the default plotline, named “main”. Plotlines follow sequentially, and have to be triggered in order, so if you want to throw in a non-linear scene that isn’t dependent on unlocking the previous ones, add a “PLOTLINE” property and assign a name other than “main”.

**Example:**

```
Begin
Where Am I?
Plotline main
Music arid
Background pit
Demo Music arid_compr
Act 1
Scene 2
```

## END

Ends a scene. Expected only after a "Begin" block.

**Usage:**

`End`

**Example:**

```
Begin
A Cool Scene

Intro 1

Terevan
Wow, what a cool scene.

End
```

**Notes:**
Because anything after a matched keyword is treated as a parameter, and END uses no parameters, you can use "End scene" as a valid alias for “End” because “scene” will just be ignored.

## NAMES

Must occur at the beginning of the document. This block is simply a list of defined names that you plan to use in speech blocks later on. This is the only block that may occur outside of BEGIN / END blocks. This is only really important for names that include spaces in them, so that the parser can properly match them and still be able to interpret remaining words on that line as parameters.

**Usage:**
```
Names
<Name1>
<Name2>
<Etc>
```

**Example:**

```
Names
Terevan
Javir
Bitey
The Many Voices of the Hollow Mind
```

## DUB

(As in "I dub thee…" ) - prompts the player to name a character.

**Usage:**

```
Dub <Character>
<Blurb>
```

**Example:**

```
Dub Ularishtim
```

**Notes:**

The `<Character>` parameter must *exactly* match one of the names registered in the NAMES block for this to function properly. The first line provided with this block will be displayed as blurb text in the YouGot screen.

## JOIN

Adds a character to the party instantly and silently, skipping the name screen altogether. You can still invoke a DUB block later to name this character.

**Usage:**

```
Join <Character> ?<Name> ?<Class>
```

**Example:**

```
Join Latesh
Name Captain
Class mcguffin
```

**Notes:**

* The purpose of this command is to add characters to the party before their name is known, or to bootstrap the party with characters that the engine needs to function (such as allies or the mcguffin) without interrupting the flow of the story.
* If you don’t supply a name, the character will join with their default name.
* If you don’t supply a class, the class is derived from the `<Character>` tag (lowercase, strips punctuation and spaces)

## PLAINTEXT

Prints plain white text on a black background.

**Usage:**

```
Plaintext
<Text>
```

**Example:**

```
Plaintext
My name is Azra.
```

## NARRATOR

Starts a new speech line without a portrait, in the universal voice and styling of the narrator.

**Usage:**

```
Narrator
<Text>
```

**Example:**

```
Narrator
If only Bob had known what was in store for him that afternoon…
```

## COMMENT

For jotting down some notes you want the parser to ignore

**Usage:**

```
Comment
<Text>
```

**Example:**

```
Comment
Remember to add some more funny lines here.
```

## PLACEHOLDER

Similar to a comment, but this is actually displayed during the cutscene, but as an obvious placeholder note. Useful for WIP cut scenes to indicate something that should be there but isn’t finished yet. This will display a simple text overlay preceeded by "PLACEHOLDER: “ and then your text.

**Usage:**

```
Placeholder
<Text>
```

**Example:**

```
Placeholder
There should be a picture of a big scary dragon now.
```

**Notes:**

Since PLACEHOLDER takes no parameters, you can use something like "PLACEHOLDER NOTE" as an alias for PLACEHOLDER, it will just effectively ignore any words after it matches “PLACEHOLDER”.

## TUTORIAL

Starts a tutorial pop up. Each line in the block will be an individual message to click-through (just like with regular dialogue).

**Usage:**

```
Tutorial <Title>
<Text>
```

**Example:**

```
Tutorial
This is your main character, Azra. She can’t move.
Monsters come from here. Don’t let them reach Azra!
Right now the game is PAUSED. Click here to get things started.
```

**Note:**

We will almost certainly extend this with all sorts of special notation to do whiz-bang things like point at stuff with arrows. I think that can be done entirely just by tacking on new parameters to the keyword and using single-line blocks as necessary. If that gets too complicated we can just leave all the special tutorial triggers in their own file that just references the tutorial in the script.

## NEWGAME

Should always come immediately after a BEGIN block.

Indicates current scene is to be played immediately as soon as a new game starts with no other requirements.

**Usage:**

```
Newgame
```

**Example:**

```
Begin
The First Cutscene

Newgame

Narrator
This is the first cutscene...
```

## INTRO

Should always come immediately after a BEGIN block.

Indicates current scene is an intro to be played immediately before a battle

**Usage:**

Intro `<Pearl>`

**Example:**

```
Begin
Something Interesting

Intro 7

Narrator
Right before battle number 7 started, something interesting happened...
```

## BATTLE

Should always come immediately after a BEGIN block.

Indicates current scene is to be played DURING a battle

**Usage:**

```
Battle <Pearl>
```

**Example:**

```
Begin
A Difficult Fight

Battle 7

Terevan
Wow, battle number 7! This sure is a difficult fight!
```

## OUTRO

Should always come immediately after a BEGIN block.

Indicates current scene is an outro to be played immediately after a battle


**Usage:**

```
Outro <Pearl>
```

**Example:**

```
Begin
The Delicious aftermath

Outro 7

Terevan
Man, what a terrible fight.
Only one thing to do…
FEAST UPON THE BODIES!!!
```

## OVERWORLD

Should always come immediately after a BEGIN block.

Indicates current scene is to be played overlaid on top of the overworld, once the indicated pearl has been completed, but after any outro has been viewed.

If no pearl ID is supplied, this will trigger the first time you hit the overworld.

**Usage:**

```
Overworld ?<Pearl>
```

**Example:**

```
Begin
Where Did I Put That Thing

Overworld 7

Javir
Hey Terevan, do you know where I put that thing?
```

## PARTY

Should always come immediately after a BEGIN block.

Indicates current scene is to be played on top of the party screen once the player enters, provided the indicated pearl has been completed. Note that this does *not *include reward screens!

If no pearl ID is provided this will trigger the first time you open the party screen.

You can optionally indicate a specific section of the party screen that triggers the scene.

**Usage:**

```
Party ?<Pearl> ?<Section>
```

**Example:**

```
Begin
Loose Change

Party 7 equip

Javir
Hey, look what I found in my pocket!
```

**Sections:**

```
Equip <?characterClass> <?characterHandle>
Skills <?characterClass> <?characterHandle>
```

(Use just the section word and it will trigger as soon as you enter that mode, indicate a character class and it will trigger when you enter that mode for that class of character, and you can further restrict it to an individual character by supplying their handle).
	

## TOWN

Should always come immediately after a BEGIN block.


Indicates current scene is to be played on top of the indicated town once the player enters, (and optionally only if the indicated pearl has been completed)


If no pearl ID is provided, this will trigger the first time you enter the indicated town.

You can optionally indicate a specific town section that triggers the scene.

**Usage:**

```
Town <Town> ?<Pearl> ?<Section>
```

**Example:**

```
Begin
Welcome to Miami

Town Miami

Pearl 7

Javir
Wow! I didn’t know Miami was in this game! Let’s hit the beach!
```

**Example 2:**

```
Begin
Hot Dog!

Town Miami

Pearl 7

Section food

Comment
This scene is triggered when the town "miami" is entered after battle “7” is completed, and the “food” button is pressed for the first time, which opens the item store for “food” items.

Javir
Wow! Hot dogs!
```

**Notes:**

All town IDs are also pearl IDs, but not all pearl IDs are town IDs (they could also be battles, etc). You can trigger cutscenes related to towns just by using INTRO and OUTRO, but you use TOWN specifically for cutscenes meant to be directly overlaid on the town interface itself.

## REWARDS

Should always come immediately after a BEGIN block.

Indicates current scene is to be played on top of the post-battle rewards screen for the indicated battle

**Usage:**

```
Rewards <Pearl>
```

**Example:**

```
Begin
Make it Rain

Rewards 7

Javir
Look at all this loot!
```

## `<SPEECH>`

Starts a new speech line with a portrait. If no emote is supplied, uses the default portrait.

**Usage:**

```
<Speaker> ?<Emote>
<Text>
```

**Example:**

```
Terevan
Hey is it just me or does it smell like Updog in here?

Javir puzzled
What’s Updog?

Terevan delighted
Not much, what’s up with you?

Javir facepalm
groan...
```

# Output

## `game_progression.xml`

This file will include a list of inferred triggers that can be copy-pasted into the main game_progression.xml file as a series of "plotline" triggers.

## `scenes/<locale>/<name>.xml`

Every scene gets its own file to contain its dialogue. The name is generated from the title by forcing to lowercase, removing punctuation, and replacing spaces with underscores. So, "Title of the Scene" will be saved as *scenes/title_of_the_scene.xml*. The file will be referenced in the game triggers by the same string id. The scene information will be stored in a locale-specific folder. All human-presented text will be replaced by automatically generated firetongue flags.

## `locales/en-US/scenes.tsv`

All of the firetongue flags from the previous file will be indexed here along with their corresponding text content, in one big file.

