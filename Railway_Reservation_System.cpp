#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

// Structure to represent a reservation
struct Reservation {
    int seatNumber;
    char passengerName[50];
};

// Function to display the menu
void displayMenu() {
    printf("\nRailway Reservation System Menu\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Reservation\n");
    printf("3. Display Reservations\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Reservation reservations[MAX_SEATS];
    int choice, numReservations = 0;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Book a Ticket
                if (numReservations < MAX_SEATS) {
                    printf("Enter passenger name: ");
                    scanf("%s", reservations[numReservations].passengerName);
                    reservations[numReservations].seatNumber = numReservations + 1;
                    numReservations++;
                    printf("Ticket booked successfully.\n");
                } else {
                    printf("Sorry, the train is full.\n");
                }
                break;

            case 2: // Cancel a Reservation
                if (numReservations > 0) {
                    int seatToCancel;
                    printf("Enter seat number to cancel: ");
                    scanf("%d", &seatToCancel);

                    if (seatToCancel >= 1 && seatToCancel <= numReservations) {
                        // Shift remaining reservations
                        for (int i = seatToCancel - 1; i < numReservations - 1; i++) {
                            reservations[i] = reservations[i + 1];
                            reservations[i].seatNumber = i + 1;
                        }
                        numReservations--;
                        printf("Reservation canceled successfully.\n");
                    } else {
                        printf("Invalid seat number.\n");
                    }
                } else {
                    printf("No reservations to cancel.\n");
                }
                break;

            case 3: // Display Reservations
                printf("\n--- List of Reservations ---\n");
                for (int i = 0; i < numReservations; i++) {
                    printf("Seat %d: %s\n", reservations[i].seatNumber, reservations[i].passengerName);
                }
                printf("\n");
                break;

            case 4: // Quit
                printf("Thank you for using the Railway Reservation System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
