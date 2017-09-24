#include <yaml_parser.hpp>

#include <boost/property_tree/ptree.hpp>
#include <fstream>
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

void read_yaml(std::istream& stream, boost::property_tree::ptree& pt)
{
    YAML::Node node = YAML::Load(std::string(std::istreambuf_iterator<char>(stream), {}));
    read_yaml(node, pt);
}

void read_yaml(const std::string& fileName, boost::property_tree::ptree& pt)
{
    YAML::Node node = YAML::LoadFile(fileName);
    read_yaml(node, pt);
}

void write_yaml(YAML::Node& node, const boost::property_tree::ptree& pt)
{
    using boost::property_tree::ptree;

    for (auto& item: pt) {
        auto key = item.first;
        YAML::Node child;
        write_yaml(child, item.second);
        if (key == "") {
            node.push_back(child);
        } else {
            node[key] = child;
        }
    }

    if (pt.get_value<std::string>() != "") {
        node = YAML::Node(pt.get_value<std::string>());
    }
}

void write_yaml(std::ostream& stream, const boost::property_tree::ptree& pt)
{
    YAML::Node node;
    write_yaml(node, pt);
    stream << node;
}

void write_yaml(const std::string& fileName, const boost::property_tree::ptree& pt)
{
    std::ofstream stream(fileName);
    write_yaml(stream, pt);
}

}
