# Simulador de Cajero Automático en C

Este programa de consola simula un cajero automático con menú interactivo.  
Permite consultar saldo, depositar, retirar dinero y ver los últimos movimientos.

## Funcionalidades
- Ingreso con PIN (máximo 3 intentos).
- Menú principal con opciones:
  1. Consultar saldo
  2. Depositar dinero
  3. Retirar dinero
  4. Ver últimos movimientos
  5. Salir
- Saldo inicial: $500.000.
- Depósitos: monto mayor que 0.
- Retiros: monto mayor que 0, no superar saldo, múltiplo de $10.000.
- Guarda los últimos 5 movimientos.

## Compilación
```bash
gcc -std=c99 -Wall main.c -o cajero
