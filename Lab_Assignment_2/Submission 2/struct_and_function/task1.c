#include <stdio.h>
#include <string.h>

struct Item
{
    int quantity;
    int unit_price;
};

int item_cost(struct Item item)
{
    return item.quantity * item.unit_price;
}

int main()
{
    int paratha_quantity = 0;
    int paratha_price = 0;
    int vegetable_quantity = 0;
    int vegetable_price = 0;
    int water_quantity = 0;
    int water_price = 0;
    int number_of_people = 0;
    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha_quantity);
    printf("Unit Price: ");
    scanf("%d", &paratha_price);
    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetable_quantity);
    printf("Unit Price: ");
    scanf("%d", &vegetable_price);
    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water_quantity);
    printf("Unit Price: ");
    scanf("%d", &water_price);
    printf("Number of People: ");
    scanf("%d", &number_of_people);
    printf("Paratha Price: %d, Paratha Quantity: %d, Vegetable Price: %d, Vegetable Quantity: %d, Water Price: %d, Water Quantity: %d\n",
           paratha_price,
           paratha_quantity,
           vegetable_price,
           vegetable_quantity,
           water_price,
           water_quantity);

    struct Item paratha;
    paratha.quantity = paratha_quantity;
    paratha.unit_price = paratha_price;

    struct Item vegetable;
    vegetable.quantity = vegetable_quantity;
    vegetable.unit_price = vegetable_price;

    struct Item water;
    water.quantity = water_quantity;
    water.unit_price = water_price;

    float total_price = item_cost(paratha) +
                        item_cost(vegetable) +
                        item_cost(water);

    float individual_cost = total_price / number_of_people;
    printf("Individual people will pay: %.2f", individual_cost);
    return 0;
}
