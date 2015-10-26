// Library with functions to calculate the area of geometric figures

float calculate_triangle_area(float *measures)
{
	float calculated_area;
	float base = *measures;
	float height = *(measures + 1);
	calculated_area = ((base * height)/2.0);
	return calculated_area;
}

float calculate_rectangle_area(float *measures)
{
	float calculated_area;
	float base = *measures;
	float height = *(measures +1);
	calculated_area = (base * height);
	return calculated_area;
}

float calculate_square_area(float *measures)
{
	float calculated_area;
	float lado = *measures;
	calculated_area = (lado * lado);
	return calculated_area;
}

float calculate_trapeze_area(float *measures)
{
	float calculated_area;
	float larger_base = *measures;
	float smaller_base = *(measures + 1);
	float height = *(measures + 2);
	calculated_area = (((larger_base + smaller_base) * height)/2.0);
	return calculated_area;
}

float calculate_circle_area(float *measures)
{
	float calculated_area;
	float radius = *measures;
	calculated_area = (3.14159 * (radius * radius));
	return calculated_area;
}