#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <sstream>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <yaml_parser.hpp>

using namespace boost::property_tree;
using namespace yaml_parser;

const char* str_yaml =
    "a: b\n"
    "c: d\n"
    "e:\n"
    "  f: g\n"
    "  h: i\n"
    "  j:\n"
    "    - k\n"
    "    - l"
    ;

const char* str_json =
    "{\n"
    "    \"a\": \"b\",\n"
    "    \"c\": \"d\",\n"
    "    \"e\": {\n"
    "        \"f\": \"g\",\n"
    "        \"h\": \"i\",\n"
    "        \"j\": [\n"
    "            \"k\",\n"
    "            \"l\"\n"
    "        ]\n"
    "    }\n"
    "}\n"
    ;

BOOST_AUTO_TEST_CASE(case1)
{
    std::stringstream ss_yaml(str_yaml);
    std::stringstream ss_json;

    ptree pt;
    read_yaml(ss_yaml, pt);
    write_json(ss_json, pt);

    BOOST_CHECK_EQUAL(ss_json.str(), str_json);
}

BOOST_AUTO_TEST_CASE(case2)
{
    std::stringstream ss_json(str_json);
    std::stringstream ss_yaml;

    ptree pt;
    read_json(ss_json, pt);
    write_yaml(ss_yaml, pt);

    BOOST_CHECK_EQUAL(ss_yaml.str(), str_yaml);
}

BOOST_AUTO_TEST_CASE(case3)
{
    std::stringstream ss_json1(str_json);
    std::stringstream ss_json2;

    ptree pt1;
    ptree pt2;
    read_json(ss_json1, pt1);
    write_yaml("Test.yaml", pt1);
    read_yaml("Test.yaml", pt2);
    write_json(ss_json2, pt2);

    BOOST_CHECK_EQUAL(ss_json2.str(), str_json);
}
