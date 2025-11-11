#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure for Time
typedef struct {
    int hour;
    int minute;
} TIME;

// Structure for Train Information
typedef struct {
    int train_no;
    char train_name[50];
    TIME departure;
    TIME arrival;
    char start_station[50];
    char end_station[50];
} TRAIN_INFO;

// Function to display train info
void displayTrain(TRAIN_INFO t) {
    printf("\nTrain No.: %d", t.train_no);
    printf("\nTrain Name: %s", t.train_name);
    printf("\nDeparture: %02d:%02d", t.departure.hour, t.departure.minute);
    printf("\nArrival: %02d:%02d", t.arrival.hour, t.arrival.minute);
    printf("\nStart Station: %s", t.start_station);
    printf("\nEnd Station: %s\n", t.end_station);
}

// (a) List trains sorted by train number from a particular station
void listTrainsFromStation(TRAIN_INFO trains[], int n, char station[]) {
    int i, j;
    TRAIN_INFO temp;
    
    // Sort by train number
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (trains[i].train_no > trains[j].train_no) {
                temp = trains[i];
                trains[i] = trains[j];
                trains[j] = temp;
            }
        }
    }

    printf("\nTrains departing from %s:\n", station);
    int found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(trains[i].start_station, station) == 0) {
            displayTrain(trains[i]);
            found = 1;
        }
    }
    if (!found) printf("No trains found from this station.\n");
}

// (b) List trains that depart from a particular station at a particular time
void listTrainsAtTime(TRAIN_INFO trains[], int n, char station[], TIME time) {
    int found = 0;
    printf("\nTrains departing from %s at %02d:%02d:\n", station, time.hour, time.minute);
    for (int i = 0; i < n; i++) {
        if (strcmp(trains[i].start_station, station) == 0 &&
            trains[i].departure.hour == time.hour &&
            trains[i].departure.minute == time.minute) {
            displayTrain(trains[i]);
            found = 1;
        }
    }
    if (!found) printf("No trains found at this time.\n");
}

// (c) List trains that depart within next one hour of given time
void listTrainsWithinOneHour(TRAIN_INFO trains[], int n, char station[], TIME time) {
    int found = 0;
    printf("\nTrains departing from %s within one hour of %02d:%02d:\n", station, time.hour, time.minute);

    int givenMinutes = time.hour * 60 + time.minute;

    for (int i = 0; i < n; i++) {
        if (strcmp(trains[i].start_station, station) == 0) {
            int depMinutes = trains[i].departure.hour * 60 + trains[i].departure.minute;
            if (depMinutes >= givenMinutes && depMinutes <= givenMinutes + 60) {
                displayTrain(trains[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("No trains found in this time range.\n");
}

// (d) List trains between a pair of stations
void listTrainsBetweenStations(TRAIN_INFO trains[], int n, char start[], char end[]) {
    int found = 0;
    printf("\nTrains between %s and %s:\n", start, end);
    for (int i = 0; i < n; i++) {
        if (strcmp(trains[i].start_station, start) == 0 && strcmp(trains[i].end_station, end) == 0) {
            displayTrain(trains[i]);
            found = 1;
        }
    }
    if (!found) printf("No trains found between these stations.\n");
}

int main() {
    TRAIN_INFO trains[MAX];
    int n, choice;
    char station[50], start[50], end[50];
    TIME time;

    printf("Enter number of trains: ");
    scanf("%d", &n);
    getchar(); // clear newline

    // Input train details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of train %d:\n", i + 1);
        printf("Train No.: ");
        scanf("%d", &trains[i].train_no);
        getchar();

        printf("Train Name: ");
        fgets(trains[i].train_name, sizeof(trains[i].train_name), stdin);
        trains[i].train_name[strcspn(trains[i].train_name, "\n")] = '\0';

        printf("Departure Time (hour minute): ");
        scanf("%d %d", &trains[i].departure.hour, &trains[i].departure.minute);

        printf("Arrival Time (hour minute): ");
        scanf("%d %d", &trains[i].arrival.hour, &trains[i].arrival.minute);
        getchar();

        printf("Start Station: ");
        fgets(trains[i].start_station, sizeof(trains[i].start_station), stdin);
        trains[i].start_station[strcspn(trains[i].start_station, "\n")] = '\0';

        printf("End Station: ");
        fgets(trains[i].end_station, sizeof(trains[i].end_station), stdin);
        trains[i].end_station[strcspn(trains[i].end_station, "\n")] = '\0';
    }

    do {
        printf("\n===== Train Information Menu =====");
        printf("\n1. List trains from a station (sorted by train number)");
        printf("\n2. List trains from a station at a specific time");
        printf("\n3. List trains from a station within one hour of a given time");
        printf("\n4. List trains between two stations");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter station name: ");
                fgets(station, sizeof(station), stdin);
                station[strcspn(station, "\n")] = '\0';
                listTrainsFromStation(trains, n, station);
                break;

            case 2:
                printf("Enter station name: ");
                fgets(station, sizeof(station), stdin);
                station[strcspn(station, "\n")] = '\0';
                printf("Enter time (hour minute): ");
                scanf("%d %d", &time.hour, &time.minute);
                listTrainsAtTime(trains, n, station, time);
                break;

            case 3:
                printf("Enter station name: ");
                fgets(station, sizeof(station), stdin);
                station[strcspn(station, "\n")] = '\0';
                printf("Enter time (hour minute): ");
                scanf("%d %d", &time.hour, &time.minute);
                listTrainsWithinOneHour(trains, n, station, time);
                break;

            case 4:
                printf("Enter start station: ");
                fgets(start, sizeof(start), stdin);
                start[strcspn(start, "\n")] = '\0';
                printf("Enter end station: ");
                fgets(end, sizeof(end), stdin);
                end[strcspn(end, "\n")] = '\0';
                listTrainsBetweenStations(trains, n, start, end);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
