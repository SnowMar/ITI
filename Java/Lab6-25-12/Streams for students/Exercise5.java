import java.util.Comparator;
import java.util.Objects;
import java.util.Optional;

import static java.lang.System.out;

public class Exercise5 {
    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();
        Optional<City> highestPopulatedCapital = countryDao.findAllCountries().stream()
            .map(country -> country.getCapital())
            .map(id->cityDao.findCityById(id))
            .filter(Objects::nonNull)
            .max(Comparator.comparingInt(City::getPopulation));

        highestPopulatedCapital.ifPresent(city -> 
            System.out.println("Highest populated capital city: " + city.getName() + " (" + city.getPopulation() + ")")
        );
    }
}
