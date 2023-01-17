[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Doubly Linked List</h3>

  <p align="center">
  Implementation of the Doubly Linked List Data Structure
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <ul>
        <li><a href="#how-to-run">How to Run</a></li>
      </ul>
    <li><a href="#license">License</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This is an implementation of the <a href="https://en.wikipedia.org/wiki/Doubly_linked_list"><i>Doubly Linked List</i></a> Data Structure in C++ that I made as part of an assignment in my Data Structures Course at the University. Doubly Linked List is a special Data Strcture in which data is linked sequentially in nodes, where each node contains three things: Data, a pointer to the previous node, and a pointer to the next node. Using the pointers one can move back and forth from the initial HEAD and TAIL Node. It also contains a special class to store data (relevant to the assignment), and can be ignored if only DLL is needed. The data which is read from file, has to be in the following format:

```
    ID  Name    Price   Category    Company
```

**_ALL OF THESE NEED TO HAVE TABS IN BETWEEN THEM_**

### Built With

* [C++](https://en.wikipedia.org/wiki/C%2B%2B)



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

* C++ - Google for your OS.
* [git](https://git-scm.com)

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/saeenyoda/Doubly_Linked_List.git
   ```


<!-- USAGE EXAMPLES -->
## Usage

### How to Run
1. Open up command line or terminal and navigate to the cloned repo's directory
   ```sh
   cd "PATH-TO-DIRECTORY"
   ```
2. Run the main.cpp file (Using terminal on mac)
   ```sh
   clang++ -std=c++14 -stdlib=libc++ -I "PATH-TO-includes-FOLDER" "PATH-TO-main.cpp" "PATH-TO-item.cpp" -o out/release/main 
   ```

***NOTE:***  
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`The instructions given above are for mac and that too using the terminal. For other OS and IDEs refer to the relevant docs.`
 

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/saeenyoda/Inverted_Indexing?label=license&style=for-the-badge
[license-url]: https://github.com/saeenyoda/Inverted_Indexing/blob/master/LICENSE

