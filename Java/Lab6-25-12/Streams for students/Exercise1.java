

import java.util.*;
import java.util.stream.*;




public class Exercise1 {

   public static void main(String[] args) {
      CountryDao countryDao= InMemoryWorldDao.getInstance();
      List <City> s = countryDao.findAllCountries().stream()
      .flatMap(country -> country.getCities().stream())
      .sorted(Comparator.comparing(City::getPopulation).reversed())
      .limit(5)
      .collect(Collectors.toList());
      System.out.println("Top 5 most populated cities in the world: \n" + s);
      s.size();
   }

   

}