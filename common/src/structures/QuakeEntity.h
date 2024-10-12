#pragma once

#include "QuakeBrush.h"

#include <map>
#include <string>
#include <vector>

class QuakeEntity {
   public:
    void addBrush(const QuakeBrush& brush);
    void addProperty(const std::pair<std::string, std::string>& pair);

    std::vector<QuakeBrush>& brushes();
    const std::vector<QuakeBrush>& brushes() const;

    std::map<std::string, std::string>& properties();
    const std::map<std::string, std::string>& properties() const;

   private:
    std::vector<QuakeBrush> m_brushes;
    std::map<std::string, std::string> m_keyvalues;
};
