# <a href="url"><img src="https://images.assetsdelivery.com/compings_v2/dmstudio/dmstudio1606/dmstudio160600030.jpg" align="middle" width="100" height="100"></a> AirBnB clone - The console


## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)

## Description
This is a command line interpreter.
Standard functions and system calls employed in simple_shell include:
   ```commands
   create, show, destroy, all, update.
   ```

   ```classes
   BaseModel, User, State, Amenity, Place, Review.
   ```

   
## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [console.py] - program command line interpreter
  * `create` - create a new instance of selected class (ex: create BaseModel)
  * `show` - Prints the string representation of selected instance (ex: BaseModel existing-id)
  * `destroy` - Deletes an instance based on the class name and id (ex: destroy BaseModel 1234-1234-1234)
  * `all` - Prints all string representation of all instances based or not on the class name. (ex:  all BaseModel or $ all. )
  * `update` - Updates an instance based on the class name and id by adding or updating attribute. (ex: update BaseModel 1234-1234-1234 email "aibnb@holbertonschool.com") 
* [models/] - Package base, contains all modudes of all classes
  * `amenity.py` - module with Amenity class
  * `base_model.py` - module with BaseModel class
  * `city.py` - module with City class
  * `place.py` - module with Place class
  * `review.py` - module with Review class
  * `state.py` - module with State class
  * `user.py` - module with User class
  * `engine/` - Package whit file_sorage module
  * `__init__` - init for the package
* [models/engine/] - package, contain the file storage module
  * `file_storage.py` - file storage module
  * `__init__` - init for the package
* [models/base_model.py] - module with the BaseModel
  * `__init__` - init attributes of the class
  * `__str__` - return a specific string format
  * `save` - update the updated_at attribute and save the instance into json
  * `to_dict` - create a dictionary representation of de object
* [models/engine/file_storage.py] - module that serializes and deserializes instences to Json file and vice versa
  * `all` - return a dictionary with all instances
  * `new` - save an instance in a dicctionary "__object"
  * `save` - serialize the dicctionary reprecentation of instances into a json file
  * `reload` - deserializes the Json file to __objects 
  
 

## Requirements

The console for AirBnb clone is designed to run with `Python 3.4x ` 

## Installation

   - Clone this repository: `git clone ""`
   - Change directories into the repository: `cd AirBnb_clone`
   - Run the console in interactive mode: `./console.py`
   - Or run the console in non-interactive mode: example `echo "<command>" | ./console.py`

## Usage

The console is designed to execute commands in a similar manner to a shell, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [x] handles **;**
- [x] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [x] exit
- [x] env
- [ ] setenv
- [ ] unsetenv
- [x] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
$ ls -la
total 116
drwxrwxr-x  3 vagrant vagrant  4096 Aug 25 20:21 .
drwxr-xr-x 14 vagrant vagrant  4096 Aug 25 20:27 ..
drwxrwxr-x  8 vagrant vagrant  4096 Aug 25 20:27 .git
-rw-rw-r--  1 vagrant vagrant   160 Aug 25 00:09 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2828 Jul 31 01:52 README.md
-rw-rw-r--  1 vagrant vagrant   823 Aug 23 16:54 _strtok.c
-rw-rw-r--  1 vagrant vagrant  1967 Aug 24 16:46 coincidence.c
-rw-rw-r--  1 vagrant vagrant   216 Aug 23 16:54 concidence.c~
-rw-rw-r--  1 vagrant vagrant   241 Aug 23 16:54 exit.c
-rw-rw-r--  1 vagrant vagrant   189 Aug 23 16:54 free.c
-rw-rw-r--  1 vagrant vagrant   338 Aug 24 16:46 get_env.c
-rw-rw-r--  1 vagrant vagrant  1117 Aug 23 18:42 getargs.c
-rw-rw-r--  1 vagrant vagrant  1477 Aug 25 20:21 getline1.c
-rw-rw-r--  1 vagrant vagrant  1302 Aug 24 16:46 holberton.h
-rwxrwxr-x  1 vagrant vagrant 29371 Aug 24 16:56 hsh
-rw-rw-r--  1 vagrant vagrant  2271 Aug 25 02:52 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   167 Aug 23 16:54 prompt.c
-rw-rw-r--  1 vagrant vagrant   789 Aug 23 18:47 realloc.c
-rw-rw-r--  1 vagrant vagrant   973 Aug 24 16:51 shell.c
-rw-rw-r--  1 vagrant vagrant   527 Aug 24 16:46 spaces.c
-rw-rw-r--  1 vagrant vagrant   270 Aug 23 18:48 strcpy.c
-rw-rw-r--  1 vagrant vagrant    46 Aug 23 16:54 test
```
## Bugs
At this time, there are no known bugs.

## Authors
Sergio Zamudio | [GitHub](https://github.com/zamu5) | [Twitter](https://twitter.com/zamu55)

Juan Carlos Cortés | [GitHub](https://github.com/jucortesa) | [Twitter](https://twitter.com/jucortesa)

