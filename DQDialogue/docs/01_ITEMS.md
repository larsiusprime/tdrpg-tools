# ITEMS

A similar format to the dialogue tool can be used to generate items for the game, either for the
main series or as a mod.

# Rules

* All of the same rules from the dialogue tool apply

# Keywords

The exhaustive list of keywords:

* Class
* Item
* Words
* Special

## LANGUAGES

Must occur at the beginning of the document. This block is simply a list of defined languages that you plan to use later on.

**Usage:**
```
Languages
<language> <code>
<language> <code>
<Etc>
```

**Example:**

```
Languages
english en-us
german de-de
```

## CLASS

Defines an item class (a category of items).

**Usage:**
```
Class
<class>
<type>
<stat>
```

**Example:**
```
Class
weapon
sword
attack
```

## ITEM

Defines a specific item.

**Usage:**
```
Item
<type>
<id>
<bonus>
<cost>
```

**Example:**
```
Item
sword
1
3
50
```

## WORDS

Defines the name & description for a given item in every available language.

**Usage:**
```
Words
<type>
<id>
<language> name <name>
<language> info <description>
```

**Example:**
```
Words
sword
1
english name Stone Shiv
english info A sharp rock affixed to a wood handle. Better than nothing.
german name Steinmesser
german info Ein scharfer Stein, der an einem hölzernen Griff angebracht wurde. Besser als nichts.	
```

## SPECIAL

Defines the special abilities of a given item.

**Usage:**
```
Special
<type>
<id>
<special>
flavor <flavor>
stat <stat>
amount <amount>
time <operator> <time>
rate <operator> <rate>
versus <type>
```

**Example:**
```
Special
sword
14
augment flavor
flavor bleed
rate plus 0.05
```