//Biblioteca de Funções Geométricas

//Função para Cálculo da Área de um Triângulo
float areaTriangulo(float *medidas)
{
	float result;
	float b = *medidas;
	float h = *(medidas + 1);
	result = ((b*h)/2);
	return result;
}

//Função para Cálculo da Área de um Retângulo
float areaRetangulo(float *medidas)
{
	float result;
	float b = *medidas;
	float h = *(medidas +1);
	result = (b*h);
	return result;
}

//Função para Cálculo da Área de um Quadrado
float areaQuadrado(float *medidas)
{
	float result;
	float l = *medidas;
	result = (l*l);
	return result;
}

//Função para Cálculo da Área de um Trapézio
float areaTrapezio(float *medidas)
{
	float result;
	float bmaior = *medidas;
	float bmenor = *(medidas + 1);
	float h = *(medidas + 2);
	result = (((bmaior + bmenor)*h)/2);
	return result;
}

//Função para Cálculo da Área de um Círculo
float areaCirculo(float *medidas)
{
	float result;
	float r = *medidas;
	result = (3.14*(r*r));
	return result;
}
