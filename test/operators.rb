class Operators
	def initialize
		@result = 0
	end

	def +(value)
		@result += value
	end

	def assign(other)
		puts "yes"
	end
end

operators1 = Operators.new
operators1.assign_plus(4)
#operators2 = Operators.new
#operators1 != operators2

