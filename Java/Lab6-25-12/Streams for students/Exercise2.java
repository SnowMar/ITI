

import java.util.*;

public class Exercise2 {
    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();countryDao.findAllCountries().forEach(country -> {
            Optional<City> maxCity = country.getCities().stream()
                .max(Comparator.comparing(City::getPopulation));
            maxCity.ifPresent(city -> System.out.println("Country: " + country.getName() + ", City with max population: " + city.getName() + " (" + city.getPopulation() + ")"));

});
    }
}