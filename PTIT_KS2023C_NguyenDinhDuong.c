#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, m;
	printf("Nhap so dong cua mang 2 chieu:");
	scanf("%d",&n);
	printf("Nhap so cot cua mang 2 chieu:");
	scanf("%d",&m);
	int numbers[n][m];
	int sumNumbers;
	int currentIndex = 0;
	int min, max;
	do{
		printf("**************MENU**************\n");
		printf("1. Nhap gia tri cac phan tu cua mang.\n");
		printf("2. In cac tri cac phan tu trong mang theo ma tran.\n");
		printf("3. Tinh so luong cac phan tu le chia het cho 5 trong mang.\n");
		printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren duong bien, duong cheo chinh, duong cheo phu.\n");
		printf("5. Lua chon sap xep cac phan tu giam dan theo dong cua mang.\n");
		printf("6. Tong cac phan tu la so nguyen to trong mang.\n");
		printf("7. Chen sap xep cac phan tu tren duong cheo phu cua mang tang dan.\n");
		printf("8. Nhap gia tri mot mang 1 chieu gom n phan tu va chi so cot muon chen vao mang, thuc hien chen vao mang 2 chieu.\n");
		printf("9. Thoat.\n");
		printf("Lua chon cua ban:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap gia tri cac phan tu cua mang:\n");
				for(int i=0; i<n; i++){
					for(int j=0; j<m; j++){
						printf("numbers[%d][%d]=",i,j);
						scanf("%d",&numbers[i][j]);
					}
				}
				break;
			case 2:
				printf("Gia tri cac phan tu trong mang:\n");
				for(int i=0; i<n; i++){
					for(int j=0; j<m; j++){
						printf("%d\t",numbers[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			case 3:
				printf("Cac phan tu le trong mang chia het cho 5 la:\n");
				for(int i=0; i<n; i++){
					for(int j=0; i<m; j++){
						if(numbers[i][j]%2!=0 && numbers[i][j]%5==0){
								printf("%d\t",numbers[i][j]);
						}
					}
				}
				break;
			case 4:
				printf("Cac phan tu nam tren duong bien:\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(i==0 || i==n-1 || j ==0 || j == m-1){
							printf("%d\t",numbers[i][j]);
							min = numbers[0][0];
				            max = numbers[0][0];
				            for(int i=0;i<n;i++){
								for(int j=0;j<m;j++){
									if(min>numbers[i][j]){
										min = numbers[i][j];
									}
									if(max<numbers[i][j]){
										max = numbers[i][j];
									}
								}
							}
							printf("Gia tri lon nhat: %d - Nho nhat: %d\n",max,min);
						}
					}
				}
				if(n==m){
					printf("Cac phan tu nam tren duong cheo chinh:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i==j){
								printf("%d\t",numbers[i][j]);
								min = numbers[0][0];
								max = numbers[0][0];
								for(int i=0;i<n;i++){
									for(int j=0;j<m;j++){
										if(min>numbers[i][j]){
											min = numbers[i][j];
										}
										if(max<numbers[i][j]){
											max = numbers[i][j];
										}
									}
								}
								printf("Gia tri lon nhat: %d - Nho nhat: %d\n",max,min);
							}
						}
				    }
					printf("Cac phan tu nam tren duong cheo phu:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i+j==n-1){
								printf("%d\t",numbers[i][j]);
								min = numbers[0][0];
								max = numbers[0][0];
								for(int i=0;i<n;i++){
									for(int j=0;j<m;j++){
										if(min>numbers[i][j]){
											min = numbers[i][j];
										}
										if(max<numbers[i][j]){
											max = numbers[i][j];
										}
									}
								}
								printf("Gia tri lon nhat: %d - Nho nhat: %d\n",max,min);
							}
						}
				    }
				}else{
					printf("Day khong phai ma tran vuong, khong co cheo chinh va cheo phu\n");	
				}			
				break;
			case 5:
				for (int i=0;i<n-1;i++){
			        for(int j=i+1;j<n;j++){
			            if (numbers[i]<numbers[j]){
					        int temp = numbers[i]; 
					        numbers[i] = numbers[j]; 
					        numbers[j] = temp;
			            }
			        }
			    }
			    printf("Mang sau khi da sap xep giam dan:\n"); 
				for (int i=0;i<n;i++) {
				    printf("%d\t",numbers[i]);
                }
				break;
			case 6:
				sumNumbers = 0;
				printf("Cac so nguyen to trong mang: ");
				for(int i=0;i<currentIndex;i++){
					int isPrime = 0;
					int j;
					if(numbers[i][j]>=2){
						for(int j=2;j<=sqrt(numbers[i][j]);j++){
							if(numbers[i][j]%j==0){
								isPrime = 1;
								break;
							}
						}
					}else{
						isPrime=1;
					}
					if(isPrime==0){
						printf("%d\t",numbers[i][j]);
						sumNumbers+=numbers[i][j];
					}
				}
				printf("\nTong cac so nguyen to la: %d\n",sumNumbers);
				break;
			case 7:
				printf("Cac phan tu nam tren duong cheo phu:\n");
					for (int i=0;i<n;i++){
						for  (int j=0;j<m;j++){
							if (i+j==n-1){
								printf("%d\t",numbers[i][j]);
								for (int i=1;i<n;i++){
									for (int j=0;j<m;j++){
							            int key = numbers[i][j];
							            int j = i-1;
							            while(i>0 && j>=0 && key<numbers[i][j]){ 
							                numbers [i+1][j+1] = numbers[i][j]; 
							                j-=1;
							                i-=1;
							            }
							        }
							    numbers[i+1][j+1] = int key;
							    }
							    printf("Mang sau khi da sap xep tang dan:\n"); 
							    for (int i=0;i<n;i++) {
							    	for (int j=0;j<m;j++){
							           printf("%d\t", numbers[i][j]);
							        }
							    }
				            }
				        }
				    }
				break;
			case 8:
				int element, column;
			    printf("Nhap so phan tu cua mang:\n");
			    scanf("%d", &element);
			    printf("Nhap chi so cot muon chen vao mang:\n"); 
			    scanf("%d",&column); 
				int numbers [element];
				printf("Nhap gia tri cac phan tu mang:\n"); 
				for (int i=0;i<n;i++) {
				    printf("numbers[%d]=",i);
				    scanf("%d", &numbers[i]);
				    element = column; 
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("Vui long chon tu 1-9");							
		}	
	}while(1==1);
}
