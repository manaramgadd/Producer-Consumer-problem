default:
	g++ producer.cpp -o producer
	g++ consumer.cpp -o consumer
	
clean:
	g++ tmp.cpp -o tmpp
	./tmpp
	rm -f consumer
	rm -f producer
