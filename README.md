# MP3-TAG-READER-AND-EDITOR

1. ABOUT THE PROJECT


MP3 Tag Reader and Editor is a C programming project developed to read, display, and modify metadata information stored in MP3 audio files.
It allows users to view and edit details such as Song Title, Artist, Album, Year, Genre, and Composer without changing the actual audio content.
The project works with the ID3v2.3 tagging format.



2. HOW IT WORKS


  
  1. COMMAND-LINE ARGUMENTS: Accepts command-line options to perform reading, editing, or display help information.
  2. FILE VALIDATION: Checks whether the input file is a valid MP3 file.
  3. TAG READING: Reads the ID3v2.3 tag header and extracts metadata frames.
  4. TAG DISPLAY: Displays available information such as title, artist, album, year, genre, and composer.
  5. TAG EDITING: Allows users to modify selected metadata fields.
  6. FILE UPDATING: Updates the selected tag information while preserving the remaining MP3 data.
  7. OUTPUT: Displays the updated metadata after successful editing.


     
3. TYPES OF TAGS IDENTIFIED



------------------
Tag 	Description
------------------
TIT2	Song Title
TPE1	Artist Name
TALB	Album Name
TYER	Release Year
TCON	Music Genre
TCOM	Composer



4. OPERATIONS SUPPORTED


- -v – View MP3 file metadata.
- -e – Edit MP3 file metadata.
- --help – Display usage instructions.




5. KEY FEATURES



- Reads MP3 metadata information.
- Displays ID3v2.3 tag details.
- Supports editing of multiple metadata fields.
- Updates existing tag information.
- Handles MP3 tag headers and frame structures.
- Processes tag sizes using synchsafe integer representation.
- Preserves the actual audio content during metadata editing.
- Provides command-line-based operations.



6. TECHNOLOGIES USED



- PROGRAMMING LANGUAGE: C
- EDITOR: VS Code
- COMPILER: GCC
- CONCEPTS USED:
  - File Handling
  - Structures
  - Pointers
  - Dynamic Memory Allocation
  - Command-Line Arguments
  - Binary File Processing
  - String Handling
  - ID3v2.3 Tag Format
  - Bitwise Operations
 

  
7. APPLICATIONS



- Managing MP3 music collections.
- Viewing audio file information.
- Updating song metadata.
- Organizing music libraries.
- Correcting missing or incorrect song details.
- Understanding binary file formats.

  
8. PROJECT OUTCOME



Successfully developed an MP3 Tag Reader and Editor using C that reads, displays, and modifies ID3v2.3 metadata information. Implemented command-line operations and binary file handling to manage MP3 tags without modifying the actual audio content.

* OUPUT IMAGES

  
