#pragma once

#include <boost/property_tree/ptree.hpp>
#include <string>
#include <sstream>
#include <yaml-cpp/yaml.h>

namespace yaml_parser {

void read_yaml(const YAML::Node& node, boost::property_tree::ptree& pt)
{
    using boost::property_tree::ptree;

    switch (node.Type()) {
    case YAML::NodeType::Scalar:
        pt = ptree(node.as<std::string>());
        break;

    case YAML::NodeType::Sequence:
        pt = ptree();
        for (auto it = node.begin(); it != node.end(); ++it) {
            ptree child;
            read_yaml(*it, child);
            pt.push_back(std::make_pair("", child));
        }
        break;

    case YAML::NodeType::Map:
        pt = ptree();
        for (auto it = node.begin(); it != node.end(); ++it) {
            ptree child;
            read_yaml(it->second, child);
            pt.add_child(it->first.as<std::string>(), child);
        }
        break;

    default:
        assert(false && "Unknown node type.");
        break;
    }
}

void read_yaml(const std::string& fileName, boost::property_tree::ptree& pt)
{
    YAML::Node node = YAML::LoadFile(fileName);
    read_yaml(node, pt);
}

void read_yaml(const std::istringstream& stream, boost::property_tree::ptree& pt)
{
    YAML::Node node = YAML::Load(stream.str());
    read_yaml(node, pt);
}

}
