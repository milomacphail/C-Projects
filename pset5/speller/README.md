# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An invented long word said to mean a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

getrusage gets the resource page for "who" which can be an element, an element's children or for the calling thread.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Passing large structs by value is slow and takes up a lot of memory space. By passing or returning structs by value, copies of those structs will get placed on the stack, potentially causing stack overflow.
## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

fgetc moves through each word character by character, taking its index until EOF is reached. If that character is not /0, that character is appended to the array. If that character is numerical, we quit the word. If we hit a space or punctuation we know we have hit the end of the word and inititaliz a new node.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc will only handle characters in a word, fscanf will include punctuation and other special characters since it only reads to white space rather than the characters involved.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

So they cannot be altered.