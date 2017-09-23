#include "yaml_parser.hpp"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

int main(int argc, char** argv)
{
    using namespace yaml_parser;
    using namespace boost::property_tree;

    {
        ptree pt;
        read_yaml("test.yaml", pt);
        write_json("test.json", pt);
    }

    {
        ptree pt;
        read_json("test2.json", pt);
        write_yaml("test2.yaml", pt);
    }

    {
        ptree pt;
        read_xml("test3.xml", pt);
        write_yaml("test3.yaml", pt);
    }

    return 0;
}
