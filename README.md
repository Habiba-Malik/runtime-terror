#**Core Features:**
**File Opening (open)**

Prompts the user to enter a filename.

Attempts to open and load the file contents into a contentFile array.

If the file doesn't exist, it initializes a new empty file.

Makes a backup of the current file contents for undo purposes.

**Viewing File Contents (view)**

Displays the contents of the file line by line.

Highlights the current cursor line using >>.

Shows the current cursor position (line and column).

**Editing (edit)**

Backs up the current file content.

Allows the user to input new lines of text at the current cursor line.

Stops input when the user types "end".

Inserts lines by shifting existing content downwards.

**Saving (save)**

Prompts the user for a filename (defaulting to the opened file if none is given).

Checks for overwriting if a file with the same name exists.

Saves the content line by line to the specified file.

**Cursor Movement (movecursor)**

Allows the user to move the cursor using w, a, s, d keys.

Shows current cursor position after each move.

Ensures cursor doesn’t move out of bounds.

**Undo (undo)**

Replaces current file content with the previously backed-up version.

Backs up the current content into redobackup to enable redo later.

**Redo (redo)**

Restores the content from redobackup, effectively redoing an undone change.

#**Implementation Notes:**
**Uses global arrays (contentFile, backup, redobackup)** to manage file states.

Keeps track of lines using linecount, and cursor position with coursorLine and cursorCol.

Uses **cin.ignore()** smartly to handle input buffer issues.

Simple menu-based interface using a while loop and switch-case.

**User Interaction (Menu Options):**
1. Open         - Load a file or start a new one
2. View         - Display file content with cursor
3. Edit         - Insert new lines at the cursor
4. Save         - Save file (optionally under a new name)
5. Movecursor   - Move cursor with w/a/s/d
6. Undo         - Revert to last backup
7. Redo         - Restore from redo backup
8. Exit         - Close the program
This code is a solid foundation for a beginner-level text editor project and provides practical experience with file handling, arrays, user input, and implementing features like undo/redo from scratch.
