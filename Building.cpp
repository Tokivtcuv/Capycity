#include <iostream>
#include <string>
#include <vector>

#include "Building.h"
#include "Material.h"

// Getter & Setter
double Building::get_base_price() { return m_base_price; }
std::string Building::get_label() { return m_label; }
std::string Building::get_name() {return m_label; }
std::map<Material*, int> Building::get_material_list() {return m_material_list; }
void Building::set_name(std::string name) {
    m_name = name;
}
void Building::set_label(std::string label)
{
    m_label = label;
}
void Building::set_base_price(double price)
{
    m_base_price = price;
}

double Building::sum_material_costs()
{
    double sum = 0;
    for(std::pair<Material*, int> i : this->get_material_list())
    {
        sum += (i.first->get_price() * i.second);
    }
    return sum;
}
double Building::total_costs()
{
    return this->get_base_price() + this->sum_material_costs();
}
void Building::generate_mat_list(int w_cnt, int i_cnt, int p_cnt)
{
    m_material_list.insert(std::pair<Material*, int>(new Wood(), w_cnt));
    m_material_list.insert(std::pair<Material*, int>(new Metal(), i_cnt));
    m_material_list.insert(std::pair<Material*, int>(new Plastic(), p_cnt));


}
double Building::get_power() { return m_power; }

/*
std::string Building::get_name() { return m_name; }
void Building::set_name(std::string new_name) { m_name = new_name; }
std::string Building::get_label() { return m_label; }
void Building::set_label(std::string new_label) { m_label = new_label;}
// std::vector<Material*> Building::get_material_list() {return m_material_list;}
std::map<Material*, int> Building::get_material_list() { return m_material_list; }
double Building::get_base_price() { return m_base_price; }
void Building::set_base_price(double new_base_price) { m_base_price = new_base_price; }

// Methods
void Building::add_materials(int w_count, int m_count, int p_count)
{
    for(int i = 0; i < w_count; i++)
    {
        Material* m1 = new Wood();
        m_material_list.push_back(m1);
    }

    for(int i = 0; i < m_count; i++)
    {
        Material* m2 = new Metal();
        m_material_list.push_back(m2);
    }

    for(int i = 0; i < p_count; i++)
    {
        Material* m3 = new Plastic();
        m_material_list.push_back(m3);
    }
}

std::string Building::list_materials()
{
    std::string list;
    for(auto it : m_material_list)
    {
        list += it->get_name() + " ";
        // std::cout << it->get_name() + " ";
    }
    return list;
}

double Building::total_material_costs()
{
    double sum = 0;
    for(auto it : m_material_list)
    {
        sum += it->get_price();
    }
    return sum;
}

double Building::total_costs()
{
    return get_base_price() + total_material_costs();
}
*/

// Constructors
Hydropowerstation::Hydropowerstation()
{
    this->set_name("Hydropowerstation");
    this->set_label("H");
    this->set_base_price(100);
    //this->add_materials(3,7,12);
    this->generate_mat_list(5,10,15);
}

Windpowerstation::Windpowerstation()
{
    this->set_name("Windpowerstation");
    this->set_label("W");
    this->set_base_price(150);
    //this->add_materials(5,10,3);
    this->generate_mat_list(10,5,15);
}

Solarpanel::Solarpanel()
{
    this->set_name("Solarpanel");
    this->set_label("S");
    this->set_base_price(200);
    //this->add_materials(2,9,6);
    this->generate_mat_list(15,10,5);
}