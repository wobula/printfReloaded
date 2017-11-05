# printfReloaded
The OG C-language formatting function re-re-written

## Intro:

Since I've been a student at 42 silicon valley, I've observed countless students struggle with the difficulty involved in recoding this classic C function.  The most common frustration about printf is that it's 'tedious' because there is so much damn functionality you have to code for.  I had a similar experience the first time I coded printf.  I hated coding printf.  Hated!  I spent a month being miserable.  But upon a second coding, I've now decided that printf is one of my favorite projects in the 42 curriculum.

The key to making a good printf consists in making good broad level architectural choices, so that, later on, when we're knee deep in the formatting portions of the function, all our data will be organized clean, and tidy.

Toward that end, this recoding has been guided by three principles:

1. Say no to malloc.
2. Stay organized: use structs.
3. Simplify.  Simplify.  Simplify.

## Explanation:

1. Malloc may seem like our friend at first glance: instant memory!  It is not. Malloc is a trap, especially in big functions like printf.  Malloc requires that we keep track of every single byte of data it gives us so that we can free it.  Over the course of hundreds of lines of code and several weeks of coding, many tired programmers forget their own variables--myself included.  This is how memory leaks start.  One other tidbit of information about malloc is that it requires a lot of hidden overhead.  Malloc keeps track of its own memory by creating a linked list that systematizes all that data.  And, while the original C-programmers are good, linked lists are, by definition, not very fast.  Keep it simple.  Don't introduce complexity where its not needed.  Say no to malloc. Stack memory is your friend.

2. Structs might seem intimidating to the newbie programmer, but, in fact, structs are our best friends (especially stack structs).  Structs give us a way to stay organized.  Create a struct inside of a header file, and we can add and remove variables anywhere in our program by simply changing the header file.  This is an awesome tool.  But be careful: this same freedom of creating variables can also lead to bloated structs.  Try to be hard on yourself: if you can get rid of a variable in your struct, always do so.  Make them compact and pretty.  A simple struct is a happy struct.  :D

3. Printf is a huge function.  To keep it from becoming too big of a monster, always, always, always compartmentalize and compress your code.  Doing so makes it easier to read, simpler to plan, and more fun to work with.
