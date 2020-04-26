//Allan Sur
package Sorting;
import java.util.*;


import java.util.LinkedList;

public class SortingTest<E> implements Sorting<E>{
	int middle, lowI, highI;
	
	public static void main(String[] args) {
		int[] tests = new int[] {10, 50, 150, 300, 500, 10000, 15000};
		SortingTest newSort = new SortingTest();
		
		System.out.println("Welcome to the list sorting tester");
		LinkedList list1 = new LinkedList();
		LinkedList list2 = new LinkedList();
		LinkedList list3 = new LinkedList();
		Random r = new Random();
		Scanner s = new Scanner(System.in);
		int choice = 0;
		boolean marker = true;
		int size = 0;
		while(marker != false) {
			
			System.out.println("Please pick an test size: 10, 50, 100, 150, 300, 500, 1000 or 1500");
			try {
				size = s.nextInt();
			}
			catch(Exception e) {
				//this method is to make sure that the input is only an integer, if it is not, the program spits out lines asking for another int and will continue and not break the program.
				System.out.println("Please only enter an integer.");
				System.out.println("Please enter another test size: 10, 50, 100, 150, 300, 500, 1000 or 1500");
				s.nextLine();
				size = s.nextInt();
			}
			int a  = 0;
			while (a < size) {
				list1.add(a, r.nextInt());
				list2.add(a, r.nextInt());
				list3.add(a, r.nextInt());
				a++;
			}
			
			System.out.println("All lists of size " + size + " have now been loaded. Please pick an option");
			System.out.println("1. Insertion Sort");
			System.out.println("2. Quick Sort");
			System.out.println("3. Merge Sort");
			System.out.println("4. All Sorts");
			System.out.println("5. Exit");
			choice = s.nextInt();
			
			switch(choice) {
				case 1: System.out.println("*INSERTION SORT*");
					long time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, false);
					long time2 =  System.nanoTime();
				
					long finalTime1 = time2 - time1;

				
					time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					long finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, true);
					time2 = System.nanoTime();
				
					long finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					break;
					
				case 2:
					System.out.println("*QUICKSORT*");
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime1 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, true);
					time2 = System.nanoTime();
				
					finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					break;
					
				case 3:
					System.out.println("*MERGE SORT*");
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, false);
					time2 = System.nanoTime();
				
					finalTime1 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, false);
					time2 = System.nanoTime();
				
					finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, true);
					time2 = System.nanoTime();
				
					finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					break;
				case 4:
					System.out.println("NOW RUNNING ALL SORTS");
					System.out.println("The program is running, please wait for results");
					System.out.println("*INSERTION SORT*");
					time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime1 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.insertionSort(list1, 0, list1.size()-1, true);
					time2 = System.nanoTime();
				
					finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					//Now the quickSort method on a different random list of the same size
					System.out.println("*QUICKSORT*");
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime1 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, false);
					time2 = System.nanoTime();
				
					finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.quicksort(list2, 0, list1.size()-1, true);
					time2 = System.nanoTime();
				
					finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					
					System.out.println("*MERGE SORT*");
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, false);
					time2 = System.nanoTime();
				
					finalTime1 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, false);
					time2 = System.nanoTime();
				
					finalTime2 = time2 - time1;
				
					time1 = System.nanoTime();
					newSort.mergeSortLL(list3, true);
					time2 = System.nanoTime();
				
					finalTime3 = time2 - time1;
					
					System.out.println("UNSORTED: " + finalTime1 + " ns");
					System.out.println("SORTED " + finalTime2 + " ns");
					System.out.println("REVERSED " + finalTime3 + " ns");
					System.out.println("____________________________________");
					break;
					
					
				case 5:
					System.out.println("Thanks for using the program.");
					marker = false;
					break;
			}
		}
	}

	@Override
	public void insertionSort(LinkedList<E> list, int lowIndex, int highIndex, boolean reversed) {
		int compare;
		long time2, finalTime;
		E index;
		long time1 = System.currentTimeMillis();
		if(lowIndex == highIndex || highIndex == 0) {
			//this method allows us to check if the list is empty or not and if it is it will just return. This is also implemented for every other sort.
		return;
		}
		if(reversed == false ) {
		for(int i = 1; i < list.size(); i++) {
			 index= list.get(i);
			 int key = (int)list.get(i);
			 int j = i - 1;
			 while(j >= 0 && Integer.parseInt(list.get(j).toString()) > key) {
				 list.set(j + 1,  list.get(j));
				 j--;
			 
			}
			 list.set( j + 1,  index);
		}
		
		}
		else if(reversed == true) {
			for(int i = 1; i < list.size(); i++) {
				 index= list.get(i);
				 int key = (int)list.get(i);
				 int j = i - 1;
				 //This line beneath the comment is the one that allows my insertion sort to sort in descending order
				 while(j >= 0 && Integer.parseInt(list.get(j).toString()) < key) {
					 list.set(j + 1,  list.get(j));
					 j--;
				 
				}
				 list.set( j + 1,  index);
			}
			
		}
	}
	
	@Override
	public void quicksort(LinkedList<E> list, int lowindex, int highindex, boolean reversed) {
		if (lowindex >= highindex) {
			//another check to see if the list is empty or not in order to not break the program.
			return;
		}else if(reversed == false) {
			int pivot = partition(list, lowindex, highindex);
			quicksort(list, lowindex, pivot - 1, reversed);
			quicksort(list, pivot + 1, highindex, reversed);
		}
		else if(reversed == true) {
			int pivot = partitionReversed(list, lowindex, highindex);
			quicksort(list, lowindex, pivot -1 , reversed);
			quicksort(list, pivot +1, highindex, reversed);
		}
		}
		private static int partition(LinkedList list, int low, int high) {
			int pivot = (int)list.get(low);
			int right = high;
			int left = low + 1;

			while(left <= right) {

				while(left <= high && (int)list.get(left) <= pivot) {
					left++;
				}

				while((int)list.get(right) > pivot) {
					right--;
				}

				if( left < right) {
					swap(list, left, right);
					left++;
					right--;
				}
			}
			swap(list, low, right);
			return right;
		}
		//The only difference between the reversed partition and the regular partition is are 2 of the comparisons.
		//The second while loop was changed to > instead of <= and the third while loop was change from > to <
		private static int partitionReversed(LinkedList list, int low, int high) {
			int pivot = (int)list.get(low);
			int right = high;
			int left = low +1;
			
			while(left <= right) {

				while(left <= high && (int)list.get(left) > pivot) {
					left++;
				}

				while((int)list.get(right) < pivot) {
					right--;
				}

				if( left < right) {
					swap(list, left, right);
					left++;
					right--;
				}
			}
			
			swap(list, low, right);
			return right;
			
			}
		
			private static void swap(LinkedList list, int a, int b) {
				
				int temp =(int)list.get(a);
				list.set(a,  list.get(b));
				list.set(b,  temp);
			
			}

			@Override
            public void mergeSortLL(LinkedList<E> list, boolean reversed) {
               
				LinkedList<E> leftList = new LinkedList<E>();
                LinkedList<E> rightList= new LinkedList<E>();
                
               if(list.size() == 0) {
            	   return;
               }
                int middle = list.size()/2;
               
                for(int i = 0; i <= middle - 1; i++) {
                    if(list.size() == 1 || list.size() == 0) {
                        return;
                    }
                    else
                    	leftList.add(list.get(i));
        		}
        		for(int i = middle; i <= list.size() - 1; i++) {
        			if(list.size() == 1 || list.size() == 0) {
                        return;
        			}
        			else
        			rightList.add(list.get(i));
        		}
        		if (reversed != true) {
        		
        		mergeSortLL(leftList, reversed);
        		mergeSortLL(rightList, reversed);
        		merge(list, leftList, rightList);
        		}
        		else if(reversed == true) {

            		mergeSortLL(leftList, reversed);
            		mergeSortLL(rightList, reversed);
            		mergeReversed(list, leftList, rightList);
        		}
			}
         
            private void merge(LinkedList<E> list, LinkedList<E> left, LinkedList<E> right) {
               
                int i = 0;
                int j = 0;
                int count = 0;
                int list1 = left.size();
                int list2 = right.size();
         
                while( i < list1 && j < list2) {
                    if((int) left.get(i) <= (int) right.get(j)) {
                        list.set(count, left.get(i));
                        i++;
                    }
                    else {
                        list.set(count, right.get(j));
                        j++;
                    }
                    count++;
                }
                while (i < list1) {
                    list.set(count, left.get(i));
                    i++;
                    count++;
                }
                while(j < list2) {
                    list.set(count, right.get(j));
                    j++;
                    count++;
                }
               
            }
            //The only difference between this reverse method and the above regular merge is that in the first if statement, the <= is now changed to >= which reverse the order of our merged lists.
            private void mergeReversed(LinkedList<E> list, LinkedList<E> low, LinkedList<E> high) {
                
                int i = 0;
                int j = 0;
                int count = 0;
                
                int list1 = low.size();
                int list2 = high.size();
         
                while( i < list1 && j < list2) {
                    if((int) low.get(i) >= (int) high.get(j)) {
                        list.set(count, low.get(i));
                        i++;
                    }
                    else {
                        list.set(count, high.get(j));
                        j++;
                    }
                    count++;
                }
                while (i < list1) {
                    list.set(count, low.get(i));
                    i++;
                    count++;
                }
                while(j < list2) {
                    list.set(count, high.get(j));
                    j++;
                    count++;
                }
               
           
            
            }
	    
            
            
            } 

		
	
	

	


