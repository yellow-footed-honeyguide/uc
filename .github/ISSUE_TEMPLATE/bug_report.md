**Describe the bug**
When I run the `uc` command with the `-e` flag and provide an invalid expression, the program crashes with a segmentation fault instead of displaying an appropriate error message.

**To Reproduce**
Steps to reproduce the behavior:
1. Run command `./uc -e "1 + 2 * "`
2. See the program crash with a segmentation fault

**Expected behavior**
I expected the program to display an error message indicating that the provided expression is invalid and gracefully exit without crashing.

**Screenshots**
Not applicable.

**Environment:**
 - OS: Ubuntu 20.04
 - Version: 1.0.0

**Additional context**
I have also tried running the command with different invalid expressions, and the program consistently crashes with a segmentation fault.




