# Apollon - ForRocket based 6DoF rocket trajectory solver
<img src="https://user-images.githubusercontent.com/8069773/76425916-a54e6a00-63ed-11ea-8cc0-0d63b9b2cf9a.png" width="400px">

## Feature
* Simulate 6 degree-of-freedom rocket trajectory.
* Can also simulate 6 degree-of-freedom parachute trajectory.
* Improved airdynamics model

### Input file
* solver_config.json - launch configuration and stages info
* stage_config_list.json - config json file list at stage
  * sequence_of_event.json - SOE configuration at stage
  * rocket_config.json - structure and aerodynamics configuration at stage
  * engine_config.json - engine configuration at stage
  * extra csv file - time vs thrust, mach vs CA, etc...

## Library
* [boost](https://www.boost.org/)
* [Eigen](http://eigen.tuxfamily.org/)
* [json @nlohman](https://github.com/nlohmann/json)
* [Google Test](https://github.com/google/googletest)


## License
ForRocket is released under the [MIT License](http://opensource.org/licenses/MIT).

Copyright &copy; 2020- Susumu Tanaka
