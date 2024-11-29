#FUNCTION LOGIC
1. function receives text through a File Descriptor (usually a txt file);
3. the function reads nbytes (BUFFER_SIZE) of the text;
4. nbytes are kept in a buffer;
5. a new list node is created;
6. the last node put in the list is found and it's pointer is now pointing to the new node;
7. the read text inside the buffer is passed into the new node;
8. the new node is now in the last position of the list, pointing to NULL;
9. steps 3 to 7 are repeated until a "\n" is found;
10. the text inside the list (stored in all the created nodes) is copied into a string up to "/n";
11. the text after "\n", whoch has been red due to the BUFFER_SIZE, is put into a new node (clean node) and stored int the static variable;
13. the string previously creaed is returned to the output and the program finishes - the 1st line is now printed;
14. the program restarts, having the clean node as the head of the list (and beginning of the new line);
15. everyting is repeated until the end of the text.
