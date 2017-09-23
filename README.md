# yaml_parser

yaml_parser enables to construct a ptree ([Boost.PropertyTree](http://www.boost.org/doc/libs/1_65_1/doc/html/property_tree.html)) from a YAML file. The interface is similar to the other parsers like [json_parser](http://www.boost.org/doc/libs/1_65_1/doc/html/property_tree/parsers.html#property_tree.parsers.json_parser) and [xml_parser](http://www.boost.org/doc/libs/1_65_1/doc/html/property_tree/parsers.html#property_tree.parsers.xml_parser).

```
// Convert a YAML file into JSON and XML files, for example.
ptree pt;
read_yaml("test.yaml", pt);
write_json("test.json", pt);
write_xml("test.xml", pt);
```

Compiling yaml_parser requires [yaml-cpp](https://github.com/jbeder/yaml-cpp) and [Boost.PropertyTree](http://www.boost.org/doc/libs/1_65_1/doc/html/property_tree.html).
