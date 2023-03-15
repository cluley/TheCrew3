#include <windows.h>
#include "qSort.h"
#include "enums.h"
#include "deleter.h"
#include "vehicle.h"
#include "camel.h"
#include "rapidCamel.h"
#include "centaur.h"
#include "bootsAWD.h"
#include "magicCarpet.h"
#include "eagle.h"
#include "broom.h"

int main(int argc, char** argv) {
	int input = 0;
	do {
		int distance = 0;

		std::cout << "Добро пожаловать в гоночный симулятор!\n" <<
			"1.Гонка для наземного транспорта\n" <<
			"2.Гонка для воздушного транспорта\n" <<
			"3.Гонка для наземного и воздушного транспорта\n" <<
			"Выберите тип гонки: ";
		std::cin >> input;
		std::system("cls");

		if (static_cast<RaceType>(input) == RaceType::ground) {
			Camel camel;
            RapidCamel rCamel;
			Centaur centaur;
			BootsAWD boots4x4;

			int vhs_ctr = 0;
			do {
				std::cout << "Укажите длину дистанции (должна быть положительна): ";
				std::cin >> distance;
				std::system("cls");
				if (distance < 1) {
					std::cout << "Указана неправильная дистанция!" << std::endl;
					Sleep(1500);
					std::system("cls");
				}
			} while (distance < 1);
			
			bool camel_set = false;
			bool rCamel_set = false;
			bool centaur_set = false;
			bool boots_set = false;

			std::string regdVhs = "";
			do {
				if (vhs_ctr == 0) {
					std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;
					std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
						"1.Верблюд\n" <<
						"2.Верблюд-быстроход\n" <<
						"3.Кентавр\n" << 
						"4.Ботинки-вездеходы\n" <<
						"Выберите транспорт: ";
					std::cin >> input;
					if (input == 0) { input = 69; }
				}
				else if (vhs_ctr == 1) {
					if (camel_set) { regdVhs = camel.get_name(); }
					if (rCamel_set) { regdVhs = rCamel.get_name(); }
					if (centaur_set) { regdVhs = centaur.get_name(); }
					if (boots_set) { regdVhs = boots4x4.get_name(); }
					std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;
					std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
					 "Зарегистрированные транспортные средства: " << regdVhs << '\n';
					std::cout << 
						"1.Верблюд\n" <<
						"2.Верблюд-быстроход\n" <<
						"3.Кентавр\n" <<
						"4.Ботинки-вездеходы\n" <<
						"Выберите транспорт: ";
					std::cin >> input;
					if (input == 0) { input = 69; }
				}
				else {
					std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;
					std::cout << "Зарегистрированные транспортные средства: " << regdVhs << std::endl;
					std::cout << 
						"1.Верблюд\n" <<
						"2.Верблюд-быстроход\n" <<
						"3.Кентавр\n" <<
						"4.Ботинки-вездеходы\n" <<
						"Выберите транспорт или 0 для окончания регистрации: ";
					std::cin >> input;
				}

				if (static_cast<AllVehicles>(input) == AllVehicles::camel) {
					if (!camel_set) {
						camel_set = true;
						camel.racing(distance);
						regdVhs += ", " + camel.get_name();
						std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
						Sleep(1500);
						std::system("cls");
						vhs_ctr++;
					}
					else if (camel_set) {
						std::cout << "Верблюд уже зарегистрирован на гонку." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				}
				else if (static_cast<AllVehicles>(input) == AllVehicles::rapidCamel) {
					if (!rCamel_set) {
						rCamel_set = true;
						rCamel.racing(distance);
						regdVhs += ", " + rCamel.get_name();
						std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
						Sleep(1500);
						std::system("cls");
						vhs_ctr++;
					}
					else if (rCamel_set) {
						std::cout << "Верблюд-быстроход уже зарегистрирован на гонку." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				}
				else if (static_cast<AllVehicles>(input) == AllVehicles::centaur) {
					if (!centaur_set) {
						centaur_set = true;
						centaur.racing(distance);
						regdVhs += ", " + centaur.get_name();
						std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
						Sleep(1500);
						std::system("cls");
						vhs_ctr++;
					}
					else if (centaur_set) {
						std::cout << "Кентавр уже зарегистрирован на гонку." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				}
				else if (static_cast<AllVehicles>(input) == AllVehicles::boots4x4) {
					if (!boots_set) {
						boots_set = true;
						boots4x4.racing(distance);
						regdVhs += ", " + boots4x4.get_name();
						std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << std::endl;
						Sleep(1500);
						std::system("cls");
						vhs_ctr++;
					}
					else if (boots_set) {
						std::cout << "Ботинки-вездеходы уже зарегистрированы на гонку." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				}
				else if (input == 0) {
					do {
						std::system("cls");
						std::cout << "1.Зарегистрировать транспорт\n" <<
							"2.Начать гонку\n" <<
							"Выберите действие: ";
						std::cin >> input;
						if (input == 1) { 
							std::system("cls");
							continue;
						}
						else if (input == 2) {
							input = 0;
							break;
						}
						else {
							std::cout << "Некорректный ввод!";
							Sleep(1500);
						}
					} while (input != 1);
				}
				else {
					std::cout << "Такого ТС не существует." << std::endl;
					Sleep(1500);
					std::system("cls");
				}
			} while (input != 0);

			std::system("cls");
			std::cout << "Результаты гонки:\n";

			Vehicle** array = new Vehicle * [vhs_ctr];
			for (int i = 0; i < vhs_ctr; i++) {
				if (camel_set) {
					array[i] = &camel;
					camel_set = false;
				}
				else if (rCamel_set) {
					array[i] = &rCamel;
					rCamel_set = false;
				}
				else if (centaur_set) {
					array[i] = &centaur;
					centaur_set = false;
				}
				else if (boots_set) {
					array[i] = &boots4x4;
					boots_set = false;
				}
				else {
					continue;
				}
			}

			qSort(array, vhs_ctr);

			for (int i = 0; i < vhs_ctr; i++) {
				std::cout << i + 1 << "." << *(array[i]) << std::endl;
			}

			deleter(array);

			std::cout << "\n1.Провести еще одну гонку\n" <<
				"2.Выйти\n" <<
				"Выберите действие: ";
			std::cin >> input;
			std::system("cls");
		}
		else if (static_cast<RaceType>(input) == RaceType::air) {
				Eagle eagle;
				MagicCarpet carpet;
				Broom broom;

				int vhs_ctr = 0;
				do {
					std::cout << "Укажите длину дистанции (должна быть положительна): ";
					std::cin >> distance;
					std::system("cls");
					if (distance < 1) {
						std::cout << "Указана неправильная дистанция!" << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				} while (distance < 1);

				bool eagle_set = false;
				bool carpet_set = false;
				bool broom_set = false;

				std::string regdVhs = "";
				do {
					if (vhs_ctr == 0) {
						std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
						std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
							"1.Орёл\n" <<
							"2.Ковер-самолет\n" <<
							"3.Метла\n" <<
							"Выберите транспорт: ";
						std::cin >> input;
						if (input == 0) { input = 69; }
					}
					else if (vhs_ctr == 1) {
						if (eagle_set) { regdVhs = eagle.get_name(); }
						if (carpet_set) { regdVhs = carpet.get_name(); }
						if (broom_set) { regdVhs = broom.get_name(); }
						std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
						std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
							"Зарегистрированные транспортные средства: " << regdVhs << '\n';
						std::cout <<
							"1.Орёл\n" <<
							"2.Ковер-самолет\n" <<
							"3.Метла\n" <<
							"Выберите транспорт: ";
						std::cin >> input;
						if (input == 0) { input = 69; }
					}
					else {
						std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
						std::cout << "Зарегистрированные транспортные средства: " << regdVhs << std::endl;
						std::cout <<
							"1.Орёл\n" <<
							"2.Ковер-самолет\n" <<
							"3.Метла\n" <<
							"Выберите транспорт или 0 для окончания регистрации: ";
						std::cin >> input;
					}

					if (static_cast<AirVehicles>(input) == AirVehicles::eagle) {
						if (!eagle_set) {
							eagle_set = true;
							eagle.racing(distance);
							regdVhs += ", " + eagle.get_name();
							std::cout << "Орёл успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (eagle_set) {
							std::cout << "Орёл уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AirVehicles>(input) == AirVehicles::magicCarpet) {
						if (!carpet_set) {
							carpet_set = true;
							carpet.racing(distance);
							regdVhs += ", " + carpet.get_name();
							std::cout << "Ковер-самолет успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (carpet_set) {
							std::cout << "Ковер-самолет уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AirVehicles>(input) == AirVehicles::broom) {
						if (!broom_set) {
							broom_set = true;
							broom.racing(distance);
							regdVhs += ", " + broom.get_name();
							std::cout << "Метла успешно зарегистрирована!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (broom_set) {
							std::cout << "Метла уже зарегистрирована на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (input == 0) {
						do {
							std::system("cls");
							std::cout << "1.Зарегистрировать транспорт\n" <<
								"2.Начать гонку\n" <<
								"Выберите действие: ";
							std::cin >> input;
							if (input == 1) {
								std::system("cls");
								continue;
							}
							else if (input == 2) {
								input = 0;
								break;
							}
							else {
								std::cout << "Некорректный ввод!";
								Sleep(1500);
							}
						} while (input != 1);
					}
					else {
						std::cout << "Такого ТС не существует." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				} while (input != 0);

				std::system("cls");
				std::cout << "Результаты гонки:\n";

				Vehicle** array = new Vehicle * [vhs_ctr];
				for (int i = 0; i < vhs_ctr; i++) {
					if (eagle_set) {
						array[i] = &eagle;
						eagle_set = false;
					}
					else if (carpet_set) {
						array[i] = &carpet;
						carpet_set = false;
					}
					else if (broom_set) {
						array[i] = &broom;
						broom_set = false;
					}
					else {
						continue;
					}
				}

				qSort(array, vhs_ctr);

				for (int i = 0; i < vhs_ctr; i++) {
					std::cout << i + 1 << "." << *(array[i]) << std::endl;
				}

				deleter(array);

				std::cout << "\n1.Провести еще одну гонку\n" <<
					"2.Выйти\n" <<
					"Выберите действие: ";
				std::cin >> input;
				std::system("cls");
			}
			else if (static_cast<RaceType>(input) == RaceType::mixed) {
				Camel camel;
				RapidCamel rCamel;
				Centaur centaur;
				BootsAWD boots4x4;
				Eagle eagle;
				MagicCarpet carpet;
				Broom broom;

				int vhs_ctr = 0;
				do {
					std::cout << "Укажите длину дистанции (должна быть положительна): ";
					std::cin >> distance;
					std::system("cls");
					if (distance < 1) {
						std::cout << "Указана неправильная дистанция!" << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				} while (distance < 1);

				bool camel_set = false;
				bool rCamel_set = false;
				bool centaur_set = false;
				bool boots_set = false;
				bool eagle_set = false;
				bool carpet_set = false;
				bool broom_set = false;

				std::string regdVhs = "";
				do {
					if (vhs_ctr == 0) {
						std::cout << "Гонка смешанного типа. Расстояние: " << distance << std::endl;
						std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
							"1.Верблюд\n" <<
							"2.Верблюд-быстроход\n" <<
							"3.Кентавр\n" <<
							"4.Ботинки-вездеходы\n" <<
							"5.Орёл\n" <<
							"6.Ковер-самолет\n" <<
							"7.Метла\n" <<
							"Выберите транспорт: ";
						std::cin >> input;
						if (input == 0) { input = 69; }
					}
					else if (vhs_ctr == 1) {
						if (camel_set) { regdVhs = camel.get_name(); }
						if (rCamel_set) { regdVhs = rCamel.get_name(); }
						if (centaur_set) { regdVhs = centaur.get_name(); }
						if (boots_set) { regdVhs = boots4x4.get_name(); }
						if (eagle_set) { regdVhs = eagle.get_name(); }
						if (carpet_set) { regdVhs = carpet.get_name(); }
						if (broom_set) { regdVhs = broom.get_name(); }
						std::cout << "Гонка смешанного типа. Расстояние: " << distance << std::endl;
						std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства.\n" <<
							"Зарегистрированные транспортные средства: " << regdVhs << '\n';
						std::cout <<
							"1.Верблюд\n" <<
							"2.Верблюд-быстроход\n" <<
							"3.Кентавр\n" <<
							"4.Ботинки-вездеходы\n" <<
							"5.Орёл\n" <<
							"6.Ковер-самолет\n" <<
							"7.Метла\n" <<
							"Выберите транспорт: ";
						std::cin >> input;
						if (input == 0) { input = 69; }
					}
					else {
						std::cout << "Гонка смешанного типа. Расстояние: " << distance << std::endl;
						std::cout << "Зарегистрированные транспортные средства: " << regdVhs << std::endl;
						std::cout <<
							"1.Верблюд\n" <<
							"2.Верблюд-быстроход\n" <<
							"3.Кентавр\n" <<
							"4.Ботинки-вездеходы\n" <<
							"5.Орёл\n" <<
							"6.Ковер-самолет\n" <<
							"7.Метла\n" <<
							"Выберите транспорт или 0 для окончания регистрации: ";
						std::cin >> input;
					}

					if (static_cast<AllVehicles>(input) == AllVehicles::camel) {
						if (!camel_set) {
							camel_set = true;
							camel.racing(distance);
							regdVhs += ", " + camel.get_name();
							std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (camel_set) {
							std::cout << "Верблюд уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::rapidCamel) {
						if (!rCamel_set) {
							rCamel_set = true;
							rCamel.racing(distance);
							regdVhs += ", " + rCamel.get_name();
							std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (rCamel_set) {
							std::cout << "Верблюд-быстроход уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::centaur) {
						if (!centaur_set) {
							centaur_set = true;
							centaur.racing(distance);
							regdVhs += ", " + centaur.get_name();
							std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (centaur_set) {
							std::cout << "Кентавр уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::boots4x4) {
						if (!boots_set) {
							boots_set = true;
							boots4x4.racing(distance);
							regdVhs += ", " + boots4x4.get_name();
							std::cout << "Ботинки-вездеходы успешно зарегистрированы!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (boots_set) {
							std::cout << "Ботинки-вездеходы уже зарегистрированы на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::eagle) {
						if (!eagle_set) {
							eagle_set = true;
							eagle.racing(distance);
							regdVhs += ", " + eagle.get_name();
							std::cout << "Орёл успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (eagle_set) {
							std::cout << "Орёл уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::magicCarpet) {
						if (!carpet_set) {
							carpet_set = true;
							carpet.racing(distance);
							regdVhs += ", " + carpet.get_name();
							std::cout << "Ковер-самолет успешно зарегистрирован!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (carpet_set) {
							std::cout << "Ковер-самолет уже зарегистрирован на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (static_cast<AllVehicles>(input) == AllVehicles::broom) {
						if (!broom_set) {
							broom_set = true;
							broom.racing(distance);
							regdVhs += ", " + broom.get_name();
							std::cout << "Метла успешно зарегистрирована!" << std::endl;
							Sleep(1500);
							std::system("cls");
							vhs_ctr++;
						}
						else if (broom_set) {
							std::cout << "Метла уже зарегистрирована на гонку." << std::endl;
							Sleep(1500);
							std::system("cls");
						}
					}
					else if (input == 0) {
						do {
							std::system("cls");
							std::cout << "1.Зарегистрировать транспорт\n" <<
								"2.Начать гонку\n" <<
								"Выберите действие: ";
							std::cin >> input;
							if (input == 1) {
								std::system("cls");
								continue;
							}
							else if (input == 2) {
								input = 0;
								break;
							}
							else {
								std::cout << "Некорректный ввод!";
								Sleep(1500);
							}
						} while (input != 1);
					}
					else {
						std::cout << "Такого ТС не существует." << std::endl;
						Sleep(1500);
						std::system("cls");
					}
				} while (input != 0);

				std::system("cls");
				std::cout << "Результаты гонки:\n";

				Vehicle** array = new Vehicle * [vhs_ctr];
				for (int i = 0; i < vhs_ctr; i++) {
					if (camel_set) {
						array[i] = &camel;
						camel_set = false;
					}
					else if (rCamel_set) {
						array[i] = &rCamel;
						rCamel_set = false;
					}
					else if (centaur_set) {
						array[i] = &centaur;
						centaur_set = false;
					}
					else if (boots_set) {
						array[i] = &boots4x4;
						boots_set = false;
					}
					else if (eagle_set) {
						array[i] = &eagle;
						eagle_set = false;
					}
					else if (carpet_set) {
						array[i] = &carpet;
						carpet_set = false;
					}
					else if (broom_set) {
						array[i] = &broom;
						broom_set = false;
					}
					else {
						continue;
					}
				}

				qSort(array, vhs_ctr);

				for (int i = 0; i < vhs_ctr; i++) {
					std::cout << i + 1 << "." << *(array[i]) << std::endl;
				}

				deleter(array);
				
				std::cout << "\n1.Провести еще одну гонку\n" <<
					"2.Выйти\n" <<
					"Выберите действие: ";
				std::cin >> input;
				std::system("cls");
		}
			else {
				std::cout << "Таких гонок не существует." << std::endl;
				Sleep(1500);
				std::system("cls");
		}
	} while (input != 2);

	return 0;
}