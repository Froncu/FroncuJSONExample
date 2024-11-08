#include <FroncuJSON/value.hpp>

#include <format>
#include <iostream>

int main()
{
   fro::value const root{ "./content/pokedex.json" };

   for (fro::value const& pokemon : root["pokemon"])
      std::cout << std::format(
         "{}. {}\n",
         pokemon["id"],
         pokemon["name"]);

   return 0;
}