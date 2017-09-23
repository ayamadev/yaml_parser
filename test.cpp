#include "yaml_parser.hpp"

#include <boost/property_tree/json_parser.hpp>

int main(int argc, char** argv)
{
    using namespace yaml_parser;
    using namespace boost::property_tree;

    ptree pt;
    read_yaml("test.yaml", pt);
    write_json("test.json", pt);

    return 0;
}
