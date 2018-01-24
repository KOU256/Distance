const LONG_RADIUS = 6378137.000;
const SHORT_RADIUS = 6356752.314140;

function radianConversion(degree) {
	var radian = degree * (Math.PI / 180);
	return radian;
}
function calculateDistance() {
	var first_latitude = parseFloat(input_form.first_latitude.value, 10),
	  	first_logitude = parseFloat(input_form.first_logitude.value, 10),
	  	second_latitude = parseFloat(input_form.second_latitude.value, 10),
	 	second_logitude = parseFloat(input_form.second_logitude.value, 10),
	 	latitude_diff = radianConversion(first_latitude - second_latitude),
	 	logitude_diff = radianConversion(first_logitude - second_logitude),
	 	latitude_ave = radianConversion((first_latitude + second_latitude) / 2),
		eccentricity = ((LONG_RADIUS ** 2) - (SHORT_RADIUS ** 2)) / (LONG_RADIUS ** 2),
		w = Math.sqrt(1 - eccentricity * (Math.sin(latitude_ave) ** 2)),
		radius_of_prime_verical_circle = LONG_RADIUS / w,
		meridian_radius_of_curvature = (LONG_RADIUS * (1 - eccentricity)) / (w ** 3),
		distance = Math.sqrt(((latitude_diff * meridian_radius_of_curvature) ** 2) + (logitude_diff * radius_of_prime_verical_circle * Math.cos(latitude_ave)) ** 2); 
	document.output_form.distance.value = distance;
}