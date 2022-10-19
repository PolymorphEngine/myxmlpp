# myxmlpp (myxml++)
myxmlpp is a simple XML lib in C++ for the sake of the PolymorphEngine project.

It includes a lot of methods to perform actions on each XML node.

## Installation
```shell
git clone https://github.com/PolymorphEngine/myxmlpp.git
cd myxmlpp
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage (reading)
To load a XML file, you need to create a `myxmlpp::Doc` object
```cpp
myxmlpp::Doc doc("path/to/file.xml");
```

You now have access to the root node of the XML file
```cpp
myxmlpp::Node root = doc.getRoot();
```

Node is a class that represents a XML node. It has a lot of methods to perform actions on it. See Developper documentaion for more informations.

## Usage (writing)
To create a XML file, you need to create a `myxmlpp::Doc` object
```cpp
myxmlpp::Doc doc;
```

You can create a node (without parent) to put data in it and add it to the document
```cpp
myxmlpp::Doc doc;
myxmlpp::Node root(nullptr)
root.setTag("Hello world!");
doc.setRoot(root);
```

You can now add Node and attributes to the root node. Then, to write the XML document to the disk, you have two options.  
The first one is to use the `myxmlpp::Doc::write` method to write the document in a minimalistic way
```cpp
doc.write("path/to/file.xml");
```
The second one is to use the `myxmlpp::Doc::writeF` method to write the document in a pretty way
```cpp
doc.writeF("path/to/file.xml");
```

You can also use the `myxmlpp::Doc::setFilepath` method to not have to pass it in `write/writeF` method 
```cpp
doc.setFilepath("path/to/file.xml");
doc.write();
//or
doc.writeF();
```


## Developper documentation
See the documentation at https://polymorphengine.github.io/myxmlpp
