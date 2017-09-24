#ifndef YAML_PARSER_HPP
#define YAML_PARSER_HPP

#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <string>
#include <sstream>
#include <yaml-cpp/yaml.h>

namespace yaml_parser {

void read_yaml(const YAML::Node& node, boost::property_tree::ptree& pt);
void read_yaml(std::istream& stream, boost::property_tree::ptree& pt);
void read_yaml(const std::string& fileName, boost::property_tree::ptree& pt);
void write_yaml(YAML::Node& node, const boost::property_tree::ptree& pt);
void write_yaml(std::ostream& stream, const boost::property_tree::ptree& pt);
void write_yaml(const std::string& fileName, const boost::property_tree::ptree& pt);

}

#endif
