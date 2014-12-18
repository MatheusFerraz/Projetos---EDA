//Biblioteca de Funções Geométricas

//Função para Cálculo da Área de um Triângulo
float calcular_area_triangulo(float *vetor_medidas)
{
	float area_calculada;
	float base = *vetor_medidas;
	float altura = *(vetor_medidas + 1);
	area_calculada = ((base * altura)/2.0);
	return area_calculada;
}

//Função para Cálculo da Área de um Retângulo
float calcular_area_retangulo(float *vetor_medidas)
{
	float area_calculada;
	float base = *vetor_medidas;
	float altura = *(vetor_medidas +1);
	area_calculada = (base * altura);
	return area_calculada;
}

//Função para Cálculo da Área de um Quadrado
float calcular_area_quadrado(float *vetor_medidas)
{
	float area_calculada;
	float lado = *vetor_medidas;
	area_calculada = (lado * lado);
	return area_calculada;
}

//Função para Cálculo da Área de um Trapézio
float calcular_area_trapezio(float *vetor_medidas)
{
	float area_calculada;
	float base_maior = *vetor_medidas;
	float base_menor = *(vetor_medidas + 1);
	float altura = *(vetor_medidas + 2);
	area_calculada = (((base_maior + base_menor) * altura)/2.0);
	return area_calculada;
}

//Função para Cálculo da Área de um Círculo
float calcular_area_circulo(float *vetor_medidas)
{
	float area_calculada;
	float raio = *vetor_medidas;
	area_calculada = (3.14159 * (raio * raio));
	return area_calculada;
}
