
#ifndef FUNCIONES_VALIDARDATOS_H_
#define FUNCIONES_VALIDARDATOS_H_

/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);



/// @brief Validar valor ingresado por el usuario, debe ser tipo char
///
/// @param pNumero: es el puntero al cual la funcion va a retornar el char ingresado (si validacion esta okay)
/// @param mensaje: informa al usuario de lo que se espera que este ingrese
/// @param mensajeError: informa al usuario del error en la carga, validacion de datos incorrecta
/// @param minimo: valor minimo del rango esperado
/// @param maximo: valor maximo del rango esperado
/// @return retora 0 si es que la funcion tuvo pudo realizar la validacion
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


/// @brief Validar valor ingresado por el usuario (no valida particularmente INT o FLOAT)
///
/// @param pNumero: es el puntero al cual la funcion va a retornar el valor ingresado (si validacion esta okay)
/// @param mensaje: informa al usuario de lo que se espera que este ingrese
/// @param mensajeError: informa al usuario del error en la carga, validacion de datos incorrecta
/// @param minimo: valor minimo del rango esperado
/// @param maximo: valor maximo del rango esperado
/// @return retora 0 si es que la funcion tuvo pudo realizar la validacion
int entradaDatos_getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo);


// -----------------------------------------------------------------------------------------------------------------

/// @brief Validar valor ingresado por el usuario, debe ser tipo int
///
/// @param pNumero: es el puntero al cual la funcion va a retornar el int ingresado (si validacion esta okay)
/// @param mensaje: informa al usuario de lo que se espera que este ingrese
/// @param mensajeError: informa al usuario del error en la carga, validacion de datos incorrecta
/// @param minimo: valor minimo del rango esperado
/// @param maximo: valor maximo del rango esperado
/// @return retora 0 si es que la funcion tuvo pudo realizar la validacion
int entradaDatos_getNumeroInt(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo);



/// @brief Validar valor ingresado por el usuario, debe ser tipo float
///
/// @param pNumero: es el puntero al cual la funcion va a retornar el flota ingresado (si validacion esta okay)
/// @param mensaje: informa al usuario de lo que se espera que este ingrese
/// @param mensajeError: informa al usuario del error en la carga, validacion de datos incorrecta
/// @param minimo: valor minimo del rango esperado
/// @param maximo: valor maximo del rango esperado
/// @return retora 0 si es que la funcion tuvo pudo realizar la validacion
int entradaDatos_getNumeroFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo);



#endif /* FUNCIONES_VALIDARDATOS_H_ */
